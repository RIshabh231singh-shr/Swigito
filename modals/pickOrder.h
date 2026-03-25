#ifndef PICKORDER_H
#define PICKORDER_H

#include<iostream>
#include<string>
#include "order.h"

class pickupOrder : public order{
    private :
    string resturantAddress;

    public :
    pickupOrder(){
        resturantAddress = "";
    }
    string getType() const override {
        return "Pickup";
    }

    //Getter and Setters
    void setRestaurantAddress(const string& addr) {
        resturantAddress = addr;
    }

    string getRestaurantAddress() const {
        return resturantAddress;
    }

};


#endif
