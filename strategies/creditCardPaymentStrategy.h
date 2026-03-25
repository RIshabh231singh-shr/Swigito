#ifndef CREDITCARDPAYMENT_H
#define CREDITCARDPAYMENT_H

#include<iostream>
#include<string>
#include "paymentStrategy.h"

using namespace std;

class creditCardPayment : public paymentStrategy{
    private:
    string cardNumber;
    public:

    creditCardPayment(string const &card){
        cardNumber = card;
    }

    void pay(int amount) override{
        cout << "Paid Rs" << amount << " using Credit Card (" << cardNumber << ")" << endl;
    }
};


#endif