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
    visitedCafe = nullptr;

    if (customer.visitedCafe != nullptr)
    {
        visitedCafe = new Cafe(*customer.visitedCafe);
    }
}

// Overrides the = operator so that one customer can become another
Customer& Customer::operator=(const Customer& customer)
{
    if (this != &customer)
    {
        Cafe* newCafe = nullptr;

        if (customer.visitedCafe != nullptr)
        {
            newCafe = new Cafe(*customer.visitedCafe);
        }

        delete visitedCafe;

        location = customer.location;
        visitedCafe = newCafe;
    }

    return *this;
}

// Destructor
Customer::~Customer()
{
   delete visitedCafe;
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
    Cafe* newCafe = nullptr;

    if (cafe != nullptr)
    {
        newCafe = new Cafe(*cafe);
    }

    delete visitedCafe;
    visitedCafe = newCafe;
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