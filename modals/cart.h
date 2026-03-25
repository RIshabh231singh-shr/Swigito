#ifndef CART_H
#define CART_H

#include<iostream>
#include<vector>
#include "../modals/menuItem.h"
#include "../modals/resturant.h"

using namespace std;

class cart{
    private : 
    vector<menuItems>items;
    int total;
    Resturant* resturant;
    
    public:
    cart(){
        resturant = nullptr;
    }

    void addItems(const menuItems &item){
        if(!resturant){
            cout<<"Select the resturant first";
            return;
        }
        items.push_back(item);
    }

    int getTotalcost(){
        int total = 0;
        for(const auto &it : items){
            total += it.getPrice();
        }
        return total;
    }

    bool isEmpty() const{
        return (!resturant || items.empty());
    }

    void clear(){
        items.clear();
        resturant = nullptr;
    }

    //getter and setter fuctions
    void setResturant(Resturant *r){
        resturant = r;
    }
    Resturant* getResturant(){
        return resturant;
    }

    const vector<menuItems>& getItems() const{
        return items;
    }

};



#endif