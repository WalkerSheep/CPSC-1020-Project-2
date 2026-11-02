// Group 1: Eric Nguyen, Walker Allen, Evan Johnston
#include "Cafe.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Default constructor
Cafe::Cafe()
{
    price = 0;
    location = 0;
}

// Parameterized constructor
Cafe::Cafe(double cafePrice, double cafeLocation)
{
    price = cafePrice;
    location = cafeLocation;
}

// Sets the price
void Cafe::SetPrice(double cafePrice)
{
    price = cafePrice;
}

// Returns the price
double Cafe::GetPrice() const
{
    return price;
}

// Sets the location
void Cafe::SetLocation(double cafeLocation)
{
    location = cafeLocation;
}

// Returns the location
double Cafe::GetLocation() const
{
    return location;
}

// Returns the profit
double Cafe::GetProfit() const
{
    return profit;
}

// Returns the customer count
int Cafe::GetCustomerCount() const
{
    return customerCount;
}

// Serves the customer a coffee and increases profit
void Cafe::ServeCustomer()
{
    customerCount ++; // Add one customer

    const double productionCost = 2; // cost to produce one coffee
    profit += (price - productionCost); // Add to the profit (price of coffee - production cost)
}

// Prints out the cafeteria info
void Cafe::Print() const
{
    cout << "Total Customers: " << customerCount << endl; // Print the total customers
    cout << "Total Profit: $" << fixed << setprecision(2) << profit << endl; // Print the total profit
}