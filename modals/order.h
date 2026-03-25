#ifndef ORDER_H
#define ORDER_H

#include<iostream>
#include<vector>
#include<string>
#include "user.h"
#include "resturant.h"
#include "menuItem.h"
#include "../strategies/paymentStrategy.h"
#include "../utils/timeutil.h"
using namespace std;
class order{
    protected : 
    static int nextOrderId;
    int orderId;
    Resturant* resturant;
    user* userData;
    vector<menuItems> items; //ye objects ka vector hai
    paymentStrategy* paymentStrategydata;
    int total;
    string scheduled;

    public:
    order(){
        userData = nullptr;
        resturant = nullptr;
        paymentStrategydata = nullptr;
        total = 0.0;
        scheduled = "";
        orderId = ++nextOrderId;
    }
    
    virtual ~order() {
        delete paymentStrategydata;
    }
    bool processPayment() {
        if (paymentStrategydata) {
            paymentStrategydata->pay(total);
            return true;
        } else {
            cout << "Please choose a payment mode first" << endl;
            return false;
        }
    }
    virtual string getType() const = 0;

    //Getter and Setters
    int getOrderId() const {
        return orderId;
    }

    void setUser(user* u) {
        userData = u;
    }

    user* getUser() const {
        return userData;
    }

    void setRestaurant(Resturant* r) {
        resturant = r;
    }

    Resturant* getRestaurant() const {
        return resturant;
    }

    void setItems(const vector<menuItems>& its) {
        items = its;
        total = 0;
        for (auto &i : items) {
            total += i.getPrice();
        }
    }

    const vector<menuItems>& getItems() const {
        return items;
    }

    void setPaymentStrategy(paymentStrategy* p) {
        paymentStrategydata = p;
    }

    void setScheduled(const string& s) {
        scheduled = s;
    }

    string getScheduled() const {
        return scheduled;
    }

    double getTotal() const {
        return total;
    }

    void setTotal(int total) {
        this->total = total;
    }
};

int order :: nextOrderId = 0;


#endif
