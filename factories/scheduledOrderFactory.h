#ifndef SCHEDULED_ORDER_FACTORY_H
#define SCHEDULED_ORDER_FACTORY_H

#include "OrderFactory.h"
#include "../modals/deliveryOrder.h"
#include "../modals/pickOrder.h"
#include "../utils/timeutil.h"
using namespace std;

class ScheduledOrderFactory : public OrderFactory {
private:
    string scheduleTime;
public:
    ScheduledOrderFactory(string scheduleTime) {
        this->scheduleTime = scheduleTime;
    }

    order* createOrder(user* userdata, cart* cart, Resturant* restaurant, const vector<menuItems>& menuItems,
                        paymentStrategy* paymentStrategy, double totalCost, const string& orderType) override {
        order* order = nullptr;

        if(orderType == "Delivery") {
            auto DeliveryOrder = new deliveryOrder();
            DeliveryOrder->setUserAddress(userdata->getAddress());
            order = DeliveryOrder;
        } 
        else {
            auto PickupOrder = new pickupOrder();
            PickupOrder->setRestaurantAddress(restaurant->getaddress());
        }
        order->setUser(userdata);
        order->setRestaurant(restaurant);
        order->setItems(menuItems);
        order->setPaymentStrategy(paymentStrategy);
        order->setScheduled(scheduleTime);
        order->setTotal(totalCost);
        return order;
    }
};

#endif