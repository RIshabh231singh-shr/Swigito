#include <iostream>
#include "Swigito.h"
using namespace std;

int main() {
    // Create Swigito Object
    SwigitoApp* swigito = new SwigitoApp();

    // Simulate a user coming in (Happy Flow)
    user* u = new user(101, "Aditya", "Delhi");
    cout << "User: " << u->getName() << " is active." << endl;

    // User searches for restaurants by location
    vector<Resturant*> restaurantList = swigito->searchRestaurants("Delhi");

    if (restaurantList.empty()) {
        cout << "No restaurants found!" << endl;
        return 0;
    }
    cout << "Found Restaurants:" << endl;
    for (auto restaurant : restaurantList) {
        cout << " - " << restaurant->getname() << endl;
    }

    // User selects a restaurant
    swigito->selectRestaurant(u, restaurantList[0]);

    cout << "Selected restaurant: " << restaurantList[0]->getname() << endl;

    // User adds items to the cart
    swigito->addToCart(u, "P1");
    swigito->addToCart(u, "P2");

    swigito->printUserCart(u);

    // User checkout the cart
    order* ord = swigito->checkoutNow(u, "Delivery", new UpiPaymentStrategy("1234567890"));

    // User pay for the cart. If payment is success, notification is sent.
    swigito->payForOrder(u, ord);

    // Cleanup Code.
    delete swigito;
    delete u;

    return 0;
}
