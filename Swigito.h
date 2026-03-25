#ifndef Swigito_APP_H
#define Swigito_APP_H

#include <iostream>
#include <vector>
#include <string>
#include "modals/user.h"
#include "modals/resturant.h"
#include "modals/cart.h"
#include "manager/resturantManager.h"
#include "manager/orderManager.h"
#include "strategies/PaymentStrategy.h"
#include "strategies/upiPaymentStrategy.h"
#include "factories/nowOrderFactory.h"
#include "factories/ScheduledOrderFactory.h"
#include "service/notificationservice.h"
#include "utils/timeutil.h"
using namespace std;

class SwigitoApp {
public:
    SwigitoApp() {
        initializeRestaurants();
    }

    void initializeRestaurants() {
        // NOTE: menuItems constructor takes non-const string refs, so we use local variables.
        Resturant* restaurant1 = new Resturant("Bikaner", "Delhi");
        { string c="P1", n="Chole Bhature"; int p=120; restaurant1->addMenuItem(menuItems(c, n, p)); }
        { string c="P2", n="Samosa";        int p=15;  restaurant1->addMenuItem(menuItems(c, n, p)); }

        Resturant* restaurant2 = new Resturant("Haldiram", "Kolkata");
        { string c="P1", n="Raj Kachori";  int p=80;  restaurant2->addMenuItem(menuItems(c, n, p)); }
        { string c="P2", n="Pav Bhaji";    int p=100; restaurant2->addMenuItem(menuItems(c, n, p)); }
        { string c="P3", n="Dhokla";       int p=50;  restaurant2->addMenuItem(menuItems(c, n, p)); }

        Resturant* restaurant3 = new Resturant("Saravana Bhavan", "Chennai");
        { string c="P1", n="Masala Dosa";  int p=90;  restaurant3->addMenuItem(menuItems(c, n, p)); }
        { string c="P2", n="Idli Vada";    int p=60;  restaurant3->addMenuItem(menuItems(c, n, p)); }
        { string c="P3", n="Filter Coffee";int p=30;  restaurant3->addMenuItem(menuItems(c, n, p)); }

        RestaurantManager* restaurantManager = RestaurantManager::getInstance();
        restaurantManager->addRestaurant(restaurant1);
        restaurantManager->addRestaurant(restaurant2);
        restaurantManager->addRestaurant(restaurant3);

        // Add other sample restaurants...
    }

    vector<Resturant*> searchRestaurants(const string& location) {
        return RestaurantManager::getInstance()->searchByLocation(location);
    }

    void selectRestaurant(user* u, Resturant* restaurant) {
        cart* userCart = u->getCart();
        userCart->setResturant(restaurant);
    }

    void addToCart(user* u, const string& itemCode) {
        Resturant* restaurant = u->getCart()->getResturant();
        if (!restaurant) {
            cout << "Please select a restaurant first." << endl;
            return;
        }
        for (const auto& item : restaurant->getmenuItem()) {
            if (item.getCode() == itemCode) {
                u->getCart()->addItems(item);
                break;
            }
        }
    }

    order* checkoutNow(user* u, const string& orderType, paymentStrategy* paymentStrategy) {
        return checkout(u, orderType, paymentStrategy, new NowOrderFactory());
    }

    order* checkoutScheduled(user* u, const string& orderType, paymentStrategy* paymentStrategy, const string& scheduleTime) {
        return checkout(u, orderType, paymentStrategy, new ScheduledOrderFactory(scheduleTime));
    }

    order* checkout(user* u, const string& orderType,
        paymentStrategy* paymentStrategyData, OrderFactory* orderFactory) {
        if (u->getCart()->isEmpty())
            return nullptr;

        cart* userCart = u->getCart();
        Resturant* orderedRestaurant = userCart->getResturant();
        vector<menuItems> itemsOrdered = userCart->getItems();
        double totalCost = userCart->getTotalcost();

        order* ord = orderFactory->createOrder(u, userCart, orderedRestaurant, itemsOrdered, paymentStrategyData, totalCost, orderType);
        OrderManager::getInstance()->addOrder(ord);
        return ord;
    }

    void payForOrder(user* u, order* ord) {
        bool isPaymentSuccess = ord->processPayment();

        // clear user cart if payment is successful.
        if (isPaymentSuccess) {
            NotificationService* notification = new NotificationService();
            notification->notify(ord);
            u->getCart()->clear();
        }
    }

    void printUserCart(user* u) {
        cout << "Items in cart:" << endl;
        cout << "------------------------------------" << endl;
        for (const auto& item : u->getCart()->getItems()) {
            cout << item.getCode() << " : " << item.getName() << " : Rs." << item.getPrice() << endl;
        }
        cout << "------------------------------------" << endl;
        cout << "Grand total : Rs." << u->getCart()->getTotalcost() << endl;
    }
};

#endif