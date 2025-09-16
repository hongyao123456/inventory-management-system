# Inventory Management System 3.0

A comprehensive C++ console-based inventory management system that handles stock management, user accounts, and order processing with both file-based and database storage capabilities.

## Features

### User Management
- **User Registration**: Create new user accounts with username and password
- **User Authentication**: Secure login system with attempt limiting
- **User Dashboard**: View stock, place orders, and track order history

### Admin Management
- **Admin Authentication**: Secure admin login (username: admin, password: admin123)
- **Stock Management**: Add, update, delete, and view inventory items
- **System Monitoring**: View system logs and all order histories
- **Order Oversight**: Monitor all user orders and transactions

### Inventory System
- **Stock Tracking**: Real-time inventory management with quantity tracking
- **Item Management**: Add new items, update quantities, and remove items
- **Stock Display**: View current inventory levels

### Order Processing
- **Order Placement**: Users can place orders for available items
- **Inventory Deduction**: Automatic stock reduction upon order confirmation
- **Order History**: Track individual user orders and system-wide order history
- **Payment Processing**: Support for debit and credit card payments (with database storage)

### Data Storage
- **File-based Storage**: Order history and system logs stored in text files
- **Database Integration**: SQLite database for payment processing
- **Logging System**: Comprehensive system activity logging

## Project Structure

\\\
system3.0/
 header/                 # Header files
    order.h            # Order management declarations
    root.h             # Admin management declarations
    stock.h            # Stock management declarations
    user.h             # User management declarations
 src/                   # Source files
    home.cpp           # Main application entry point
    order.cpp          # Order processing implementation
    root.cpp           # Admin functionality implementation
    stock.cpp          # Stock management implementation
    user.cpp           # User functionality implementation
 home.exe               # Compiled executable
 order_history.txt      # Order history storage
 system.log            # System activity logs
 c.txt                 # Extended order management with database features
 README.md             # This file
\\\

## Technical Details

### Dependencies
- **C++ Standard Library**: Uses STL containers and algorithms
- **SQLite3**: For payment processing database operations
- **File I/O**: Text file storage for orders and logs
- **Threading**: Order processing simulation with delays

### Data Models

#### StockItem Structure
\\\cpp
struct StockItem {
    std::string name;    // Item name
    int quantity;        // Available quantity
};
\\\

#### Order Structure
\\\cpp
struct Order {
    string username;     // Customer username
    string itemName;     // Ordered item
    int quantity;        // Order quantity
    double totalPrice;   // Total order value
};
\\\

### Database Schema
The system includes SQLite database support for payment processing:

\\\sql
CREATE TABLE payment (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    payment_method INTEGER NOT NULL,
    card_number TEXT NOT NULL
);
\\\

## Getting Started

### Prerequisites
- C++ compiler (GCC, Clang, or MSVC)
- SQLite3 development libraries
- Windows/Linux/macOS operating system

### Compilation
\\\ash
# Compile the project
g++ -std=c++11 -o home src/*.cpp -lsqlite3

# Or use the provided executable
./home.exe
\\\

### Running the Application
1. Execute the compiled binary: \./home.exe\
2. Choose from the main menu:
   - **Administrator Login**: Access admin features
   - **User Login**: Access user features
   - **Create Account**: Register new user
   - **Exit**: Close application

## Usage Guide

### For Users
1. **Create Account**: Register with username and password
2. **Login**: Access your account
3. **View Stock**: Browse available inventory
4. **Place Order**: Order items with quantity confirmation
5. **View History**: Track your order history

### For Administrators
1. **Login**: Use admin credentials (admin/admin123)
2. **Manage Stock**: Add, update, or delete inventory items
3. **Monitor System**: View system logs and all orders
4. **Track Activity**: Monitor user actions and system events

## Configuration

### Default Stock Items
The system comes pre-loaded with sample inventory:
- Apple: 50 units
- Orange: 30 units
- Banana: 20 units

### Pricing
- Default price per unit: .00
- Total price calculated as: quantity  price_per_unit

### Security
- Admin credentials: admin / admin123
- User accounts stored in memory (not persistent)
- Maximum 2 login attempts before lockout

## Data Storage

### File-based Storage
- **order_history.txt**: All order records with timestamps
- **system.log**: System activity and admin actions

### Database Storage
- **stock.db**: SQLite database for payment processing
- Payment methods: 1 (Debit), 2 (Credit)

## System Features

### Logging
- Comprehensive activity logging with timestamps
- Admin action tracking
- Order processing logs
- System error logging

### Error Handling
- Input validation for all user inputs
- File operation error checking
- Database connection error handling
- Graceful failure recovery

### User Experience
- Clear menu navigation
- Confirmation prompts for critical actions
- Progress indicators for order processing
- Detailed error messages

## Future Enhancements

The project includes extended functionality in c.txt with:
- Enhanced payment processing
- Database integration for orders
- Advanced order management features
- Payment method tracking

## License

This project is part of a learning exercise and is available for educational purposes.

## Contributing

This appears to be a student project. For educational use and learning purposes.

---

**Note**: This system uses in-memory storage for user accounts and file-based storage for orders. For production use, consider implementing persistent user storage and enhanced security measures.
