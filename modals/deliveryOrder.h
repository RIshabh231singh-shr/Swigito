#ifndef DELIVERY_ORDER_H
#define DELIVERY_ORDER_H

#include "Order.h"
using namespace std;

class deliveryOrder : public order {
private:
    string userAddress;

public:
    deliveryOrder() {
        userAddress = "";
    }

    string getType() const override {
        return "Delivery";
    }

    //Getter and Setters
    void setUserAddress(const string& addr) {
        userAddress = addr;
    }

    string getUserAddress() const {
        return userAddress;
    }
};

#endif