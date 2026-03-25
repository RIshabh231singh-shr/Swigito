#ifndef USER_H
#define USER_H

#include<iostream>
#include<string>
#include "cart.h"

using namespace std;

class user{
    private:
    int userId;
    string name;
    string address;
    cart* Cart;

    public:
    //constructor
    user(const int &userId,const string &name,const string &address){
        this->name = name;
        this->userId = userId;
        this->address = address;
        Cart = new cart();
    }
    //destructor    
    ~user(){
        delete Cart;
    }

    //getter and setter functions
    string getName() const{
        return name;
    }
    void setName(const string &n){
        name = n;
    }

    string getAddress() const{
        return address;
    }
    void setAddress(string const &a){
        address = a;
    }

    int getUserId() const{
        return userId;
    }
    
    cart* getCart(){
        return Cart;
    }
};



#endif