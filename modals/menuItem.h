#ifndef MENUITEM_H
#define MENUITEM_H

#include<iostream>
#include<string>
using namespace std;

//making menuclass and adding getter setter function

class menuItems{
    private : 
    string code;
    string name;
    int price;

    public:
    //initialising it using constructor
    menuItems(string &code, string &name , int &price){
        this->code = code;
        this->name = name;
        this->price = price;
    }

    string getCode() const{
        return code;
    }
    void setCode(const string &c){
        if(c.empty()) return;
        code = c;
    }
    string getName() const{
        return name;
    }
    void setName(const string &n){
        if(n.empty()) return;
        name = n;
    }
    int getPrice() const{
        return price;
    }
    void setPrice(int p){
        if(p <= 0) return;
        price = p;
    }
};
#endif