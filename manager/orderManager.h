#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

#include <vector>
#include <iostream>
#include "../modals/order.h"
using namespace std;

class OrderManager {
private:
    vector<order*> orders;
    static OrderManager* instance;

    OrderManager() {
        // Private Constructor
    }

public:
    static OrderManager* getInstance() {
        if (!instance) {
            instance = new OrderManager();
        }
        return instance;
    }

    void addOrder(order* order) {
        orders.push_back(order);
    }

    void listOrders() {
        cout << "\n--- All Orders ---" << endl;
        for (auto order : orders) {
            cout << order->getType() << " order for " << order->getUser()->getName()
                    << " | Total: Rs" << order->getTotal()
                    << " | At: " << order->getScheduled() << endl;
        }
    }
};

OrderManager* OrderManager::instance = nullptr;

#endif