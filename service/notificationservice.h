#ifndef NOTIFICATION_SERVICE_H
#define NOTIFICATION_SERVICE_H

#include <iostream>
#include "../modals/order.h"
using namespace std;

class NotificationService {
public:
    static void notify(order* orderName) {
        cout << "\nNotification: New " << orderName->getType() << " order placed!" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Order ID: " << orderName->getOrderId() << endl;
        cout << "Customer: " << orderName->getUser()->getName() << endl;
        cout << "Restaurant: " << orderName->getRestaurant()->getname() << endl;
        cout << "Items Ordered:\n";

        const vector<menuItems>& items = orderName->getItems();
        for (const auto& item : items) {
            cout << "   - " << item.getName() << " (₹" << item.getPrice() << ")\n";
        }

        cout << "Total: ₹" << orderName->getTotal() << endl;
        cout << "Scheduled For: " << orderName->getScheduled() << endl;
        cout << "Payment: Done" << endl;
        cout << "---------------------------------------------" << endl;
    }
};

#endif 