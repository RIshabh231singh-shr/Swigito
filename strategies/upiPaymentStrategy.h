#ifndef UPIPAYMENT_H
#define UPIPAYMENT_H

#include<iostream>
#include<string>
#include "paymentStrategy.h"
using namespace std;

class upiPayment : public paymentStrategy{
    private:
        string mobile;
    public:
        upiPayment(const string &mob){
            mobile : mob;
        }
        void pay(int amount) override {
             cout << "Paid Rs" << amount << " using UPI (" << mobile << ")" << endl;
        }
};
#endif