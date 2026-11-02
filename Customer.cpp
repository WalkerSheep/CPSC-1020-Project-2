// Group 1: Eric Nguyen, Walker Allen, Evan Johnston
#include "Customer.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Default constructor
Customer::Customer()
{
    location = 0;
    visitedCafe = nullptr;
}

// Parameterized constructor
Customer::Customer(double customerLocation)
{
    location = customerLocation;
    visitedCafe = nullptr;
}

// Copy constructor
Customer::Customer(const Customer& customer)
{
    location = customer.location; // Copies the other customer's location
    visitedCafe = customer.visitedCafe; // Sets visitedCafe to the other customer's visitedCafe
}

// Overrides the = operator so that one customer can become another
Customer& Customer::operator=(const Customer& customer)
{
    if(this != &customer) // Make sure that this (Customer) script is not the passed customer
    {
        location = customer.location; // Copies the other customer's location
        visitedCafe = customer.visitedCafe; // Sets visitedCafe to the other customer's visitedCafe
    }
    return *this; // Return the updated customer
}

// Destructor (Does nothing lol)
Customer::~Customer()
{
    /*
⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⢻⣿⡗⢶⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣄
⠀⢻⣇⠀⠈⠙⠳⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⠶⠛⠋⣹⣿⡿
⠀⠀⠹⣆⠀⠀⠀⠀⠙⢷⣄⣀⣀⣀⣤⣤⣤⣄⣀⣴⠞⠋⠉⠀⠀⠀⢀⣿⡟⠁
⠀⠀⠀⠙⢷⡀⠀⠀⠀⠀⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⠋⠀⠀
⠀⠀⠀⠀⠈⠻⡶⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣠⡾⠋⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣼⠃⠀⢠⠒⣆⠀⠀⠀⠀⠀⠀⢠⢲⣄⠀⠀⠀⢻⣆⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢰⡏⠀⠀⠈⠛⠋⠀⢀⣀⡀⠀⠀⠘⠛⠃⠀⠀⠀⠈⣿⡀⠀⠀⠀⠀
⠀⠀⠀⠀⣾⡟⠛⢳⠀⠀⠀⠀⠀⣉⣀⠀⠀⠀⠀⣰⢛⠙⣶⠀⢹⣇⠀⠀⠀⠀
⠀⠀⠀⠀⢿⡗⠛⠋⠀⠀⠀⠀⣾⠋⠀⢱⠀⠀⠀⠘⠲⠗⠋⠀⠈⣿⠀⠀⠀⠀
⠀⠀⠀⠀⠘⢷⡀⠀⠀⠀⠀⠀⠈⠓⠒⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡇⠀⠀⠀
⠀⠀⠀⠀⠀⠈⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣧⠀⠀⠀
⠀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠁⠀⠀⠀
    */
}

// Sets the location
void Customer::SetLocation(double customerLocation)
{
    location = customerLocation;
}

// Returns the location
double Customer::GetLocation() const
{
    return location;
}

// Sets the visited cafe
void Customer::SetVisitedCafe(Cafe* cafe)
{
    visitedCafe = cafe;
}

// Returns the visited cafe
Cafe* Customer::GetVisitedCafe() const
{
    return visitedCafe;
}

// Calculates the score
double Customer::CalculateScore(const Cafe& cafe) const
{
    double cafePrice = cafe.GetPrice(); // Price of cafe
    double cafeLocation = cafe.GetLocation(); // Location of cafe

    const double distance = abs(location - cafeLocation); // Calculates the distance
    const double beachLength = 10; // Length of the beach

    const double score = (beachLength - distance) + 3 * (6 - cafePrice); // Calculates the score

    return score;
}