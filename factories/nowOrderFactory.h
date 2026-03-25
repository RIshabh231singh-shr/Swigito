#ifndef NOW_ORDER_FACTORY_H
#define NOW_ORDER_FACTORY_H

#include "orderFactory.h"
#include "../modals/deliveryOrder.h"
#include "../modals/pickOrder.h"
#include "../utils/timeUtil.h"
using namespace std;

class NowOrderFactory : public OrderFactory {
public:
    order* createOrder(user* userdata, cart* cart, Resturant* restaurant, const vector<menuItems>& menuItems,
                       paymentStrategy* paymentStrategy, double totalCost, const string& orderType) override {
        order* order = nullptr;
        if (orderType == "Delivery") {
            auto DeliveryOrder = new deliveryOrder();
            DeliveryOrder->setUserAddress(userdata->getAddress());
            order = DeliveryOrder;
        }
        else {
            auto PickupOrder = new pickupOrder();
            PickupOrder->setRestaurantAddress(restaurant->getaddress());
            order = PickupOrder;
        }
        order->setUser(userdata);
        order->setRestaurant(restaurant);
        order->setItems(menuItems);
        order->setPaymentStrategy(paymentStrategy);
        order->setScheduled(timeutil::getCurrentTime());
        order->setTotal(totalCost);
        return order;
    }
};

#endif 