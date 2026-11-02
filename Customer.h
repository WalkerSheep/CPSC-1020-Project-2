// Group 1: Eric Nguyen, Walker Allen, Evan Johnston
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Cafe.h"

class Customer {
public:
    Customer() = default;
    Customer(double customerLocation);
    Customer(const Customer& other) = default;
    Customer& operator=(const Customer& other) = default;
    ~Customer() = default;

    void SetLocation(double customerLocation);
    double GetLocation() const;

    void SetVisitedCafe(Cafe* cafe);
    Cafe* GetVisitedCafe() const;
    double CalculateScore(const Cafe& cafe) const;

private:
    double location = 0.0;
    Cafe* visitedCafe = nullptr; // Does not own or delete the cafe
};

#endif
