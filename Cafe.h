// Group 1: Eric Nguyen, Walker Allen, Evan Johnston
#ifndef CAFE_H
#define CAFE_H

class Cafe {
public:
    // Constructors
    Cafe();
    Cafe(double cafePrice, double cafeLocation);

    // Sets the price and location
    void SetPrice(double cafePrice);
    void SetLocation(double cafeLocation);

    // Returns the price, location, profit, and customer count
    double GetPrice() const;
    double GetLocation() const;
    double GetProfit() const;
    int GetCustomerCount() const;

    // Serves a customer and increases profit
    void ServeCustomer();

    // Prints the cafe information
    void Print() const;

private:
    double price = 0.0; // Price of coffee
    double location = 0.0; // Location of the cafe
    double profit = 0.0; // Total profit
    int customerCount = 0; // Total customers served
};

#endif
