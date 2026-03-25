#ifndef PAYMENT_STRATEGY_H
#define PAYMENT_STRATEGY_H

#include<iostream>
#include<string>

using namespace std;

//factory pattern ho rha hai
class paymentStrategy{
    public :
    virtual void pay(int pay) = 0; //koi aur isko define karega
    virtual ~paymentStrategy(){};
};


#endif
