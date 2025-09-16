# Inventory Management System 3.0

A C++ console-based inventory management system with User/Admin features and Order Processing.  
Supports both file-based storage and SQLite database for payments.  

---

## 🚀 Features

**User Features**  
- Register a new account (username & password)  
- Log in securely with attempt limiting  
- View available inventory  
- Place orders and view your order history  

**Admin Features**  
- Admin login (default credentials)  
- Manage inventory: add, update, delete, and list stock items  
- View all user orders and system logs  

**Order Processing & Payments**  
- Orders reduce stock automatically when processed  
- Order history stored in text file (`order_history.txt`)  
- Payment information stored using SQLite  

**Logging & Storage**  
- All system activities (login, orders, admin actions) logged in `system.log`  
- File-based storage for orders and logs  
- SQLite database used for payment-related data  

---

## 🗂 Project Structure

```

system3.0/
├─ header/
│   ├ order.h           # Declarations for order management
│   ├ root.h            # Admin management declarations
│   ├ stock.h           # Stock management declarations
│   └ user.h            # User management declarations
├─ src/
│   ├ home.cpp          # Main entry point
│   ├ order.cpp         # Order processing implementation
│   ├ root.cpp          # Admin features implementation
│   ├ stock.cpp         # Stock management implementation
│   └ user.cpp          # User features implementation
├─ home.exe              # Compiled executable
├─ order\_history.txt     # Order history records
├─ system.log            # System activity log
├─ c.txt                 # Extended order management with database features
└─ README.md             # Project documentation (this file)

````

---

## 🧰 Technical Details

### Data Structures

```cpp
struct StockItem {
    std::string name;    // Item name
    int quantity;        // Available quantity
};
````

```cpp
struct Order {
    std::string username;    // Customer username
    std::string itemName;    // Ordered item name
    int quantity;            // Quantity ordered
    double totalPrice;       // Total order value
};
```

### Database Schema

For payment storage via SQLite:

```sql
CREATE TABLE payment (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    payment_method INTEGER NOT NULL,
    card_number TEXT NOT NULL
);
```

---

## 🛠 Prerequisites & Setup

**Prerequisites**

* C++ compiler supporting C++11 or later (GCC, Clang, MSVC, etc.)
* SQLite3 development library
* Operating system: Windows, Linux, or macOS

**Compile and Run**

```bash
g++ -std=c++11 -o home src/*.cpp -lsqlite3
```

Or, use the provided executable:

```bash
./home.exe
```

**Usage Flow**

1. Run the program (`home.exe`)
2. Choose from the menu:

   * Admin Login
   * User Login
   * Create New Account
   * Exit
3. Depending on role (user or admin), select actions: view stock, place orders, view history, manage inventory, check logs, etc.

---

## 🔧 Default Configuration

* Admin credentials: **username** `admin`, **password** `admin123`
* Inventory is initially empty (you add items via admin)
* Order history and system logs stored in text files
* SQLite used only for payment data

---

## ⚠ Limitations

* User account data may not persist beyond the program's runtime unless you extend it
* Payment is only simulated (no real gateway, no encryption)
* No GUI — purely console-based interface

---

## 💡 Future Improvements

* Persist user accounts using database for durability
* Improve security: password hashing, input validation, encryption
* Support configuration file for initial inventory and settings
* (Optional) Add a simple GUI or web interface

---

## 📜 License

Licensed under the **MIT License**.


