#ifndef RESTURANT_H
#define RESTURANT_H

//code now

#include<iostream>
#include<vector>
#include<string>
#include "menuItem.h"; //using different file here
using namespace std;


class Resturant{
    private : 
    static int nextresturantId;
    int resturantId;
    string name;
    string address;
    vector<menuItems>menu;

    public : 
    Resturant(string &name , string &address){
        this->name = name;
        this->address = address;
    }
    //resturant ka destructor bnana jaruri hai ki ek baar agar resturant delete hua to sab uska delete ho jana chahiye

    ~Resturant(){
        cout << "Destroying Restaurant: " << name << ", and clearing its menu." << endl;
        menu.clear();
    }

    //adding getter and setter functions

    string getname() const{
        return name;
    }
    void setname(const string &n){
        if(n.empty()) return ;
        name = n;
    }

    string getaddress() const{
        return address;
    }
    void setaddress(const string &a){
        if(a.empty()) return;
        address = a;
    }

    const vector<menuItems> getmenuItem() const{
        return menu;
    }
};

int Resturant::nextresturantId = 0;

#endif