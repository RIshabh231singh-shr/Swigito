#ifndef ORDER_FACTORY_H
#define ORDER_FACTORY_H

#include "../modals/order.h"
#include "../modals/cart.h"
#include "../modals/resturant.h"
#include "../strategies/PaymentStrategy.h"
#include <vector>
#include <string>
using namespace std;

class OrderFactory {
public:
    virtual order* createOrder(user* userdata, cart* cart, Resturant* restaurant, const vector<menuItems>& menuItems,
                                paymentStrategy* paymentStrategy, double totalCost, const string& orderType) = 0;
    virtual ~OrderFactory() {}
};

#endif