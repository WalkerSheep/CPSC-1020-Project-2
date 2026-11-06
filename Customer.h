// Group 1: Eric Nguyen, Walker Allen, Evan Johnston
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Cafe.h"

class Customer {
public:
    // Constructors
    Customer();
    Customer(double customerLocation);

    // Copy constructor
    Customer(const Customer& customer);

    // Copy assignment operator
    Customer& operator=(const Customer& customer);

    // Destructor
    ~Customer();

    // Sets and returns the location
    void SetLocation(double customerLocation);
    double GetLocation() const;

    // Sets and returns the visited cafe
    void SetVisitedCafe(Cafe* cafe);
    Cafe* GetVisitedCafe() const;

    // Calculates the score for a cafe
    double CalculateScore(const Cafe& cafe) const;

private:
    double location = 0.0; // Location of the customer
    Cafe* visitedCafe = nullptr; // Pointer to the visited cafe
};

#endif
