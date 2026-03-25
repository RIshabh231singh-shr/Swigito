# 🍽️ Swigito — Food Delivery System (LLD)

A **Low-Level Design** implementation of a Swiggy-like food delivery platform in **C++**, demonstrating core OOP principles and classic design patterns.

---

## 📐 Design Patterns Used

| Pattern | Where Used |
|---------|-----------|
| **Singleton** | `RestaurantManager`, `OrderManager` — single global instance |
| **Strategy** | `paymentStrategy` → `UpiPaymentStrategy`, `creditCardPaymentStrategy` |
| **Factory Method** | `OrderFactory` → `NowOrderFactory`, `ScheduledOrderFactory` |

---

## 🗂️ Project Structure

```
Swigito/
├── main.cpp                        # Entry point / demo flow
├── Swigito.h                       # Core app facade (SwigitoApp)
│
├── modals/                         # Data models
│   ├── user.h                      # User with cart
│   ├── resturant.h                 # Restaurant with menu
│   ├── menuItem.h                  # Menu item (code, name, price)
│   ├── cart.h                      # Shopping cart
│   ├── order.h                     # Abstract base order
│   ├── deliveryOrder.h             # Delivery order (with address)
│   └── pickOrder.h                 # Pickup order (from restaurant)
│
├── manager/                        # Singleton managers
│   ├── resturantManager.h          # Manages all restaurants, search by location
│   └── orderManager.h             # Tracks all placed orders
│
├── factories/                      # Factory Method pattern
│   ├── orderFactory.h              # Abstract factory interface
│   ├── nowOrderFactory.h           # Creates immediate orders
│   └── scheduledOrderFactory.h    # Creates scheduled orders
│
├── strategies/                     # Strategy pattern for payments
│   ├── paymentStrategy.h           # Abstract payment interface
│   ├── upiPaymentStrategy.h        # UPI payment implementation
│   └── creditCardPaymentStrategy.h # Credit card payment implementation
│
├── service/
│   └── notificationservice.h       # Prints order confirmation
│
└── utils/
    └── timeutil.h                  # Gets current timestamp
```

---

## 🔄 Order Flow

```
User
 │
 ├─▶ searchRestaurants(location)        ← RestaurantManager (Singleton)
 │
 ├─▶ selectRestaurant(restaurant)       ← Sets restaurant on Cart
 │
 ├─▶ addToCart(itemCode)                ← Adds menuItems to Cart
 │
 ├─▶ checkoutNow() / checkoutScheduled()
 │       │
 │       └─▶ OrderFactory               ← Factory Method
 │               ├─▶ NowOrderFactory    (immediate)
 │               └─▶ ScheduledOrderFactory (future time)
 │
 └─▶ payForOrder()
         │
         ├─▶ paymentStrategy.pay()      ← Strategy Pattern
         │       ├─▶ UpiPaymentStrategy
         │       └─▶ CreditCardPaymentStrategy
         │
         └─▶ NotificationService.notify()
```

---

## ⚡ Quick Start

### Compile

```bash
g++ -std=c++17 main.cpp -o swigito
```

### Run

```bash
./swigito
```

### Expected Output

```
User: Aditya is active.
Found Restaurants:
 - Bikaner
Selected restaurant: Bikaner
Items in cart:
------------------------------------
P1 : Chole Bhature : Rs.120
P2 : Samosa : Rs.15
------------------------------------
Grand total : Rs.135

Notification: New Delivery order placed!
---------------------------------------------
Order ID: 1
Customer: Aditya
Restaurant: Bikaner
Items Ordered:
   - Chole Bhature (₹120)
   - Samosa (₹15)
Total: ₹135
Scheduled For: <current time>
Payment: Done
---------------------------------------------
```

---

## 🏗️ Key Classes

### `SwigitoApp` _(Swigito.h)_
The main **facade** that orchestrates the entire flow. Clients interact only with this class.

| Method | Description |
|--------|-------------|
| `searchRestaurants(location)` | Find restaurants by city |
| `selectRestaurant(user, restaurant)` | Attach restaurant to user's cart |
| `addToCart(user, itemCode)` | Add a menu item by code |
| `checkoutNow(user, type, payment)` | Place an immediate order |
| `checkoutScheduled(user, type, payment, time)` | Schedule a future order |
| `payForOrder(user, order)` | Process payment & send notification |
| `printUserCart(user)` | Display cart contents |

### Order Types
- **`deliveryOrder`** — stores delivery address, type = `"Delivery"`
- **`pickupOrder`** — stores restaurant pickup address, type = `"Pickup"`

### Payment Strategies
- **`UpiPaymentStrategy`** — takes a UPI mobile number
- **`creditCardPaymentStrategy`** — takes card details

---

## 📝 Notes

- All manager classes (`RestaurantManager`, `OrderManager`) use the **Singleton** pattern — only one instance exists for the lifetime of the app.
- The `menuItems` constructor takes non-const `string&` parameters; pass local variables, not string literals.
- Memory management is manual (raw pointers) — suitable for LLD demonstration purposes.
