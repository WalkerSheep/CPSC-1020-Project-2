// Group 1: Eric Nguyen, Walker Allen, Evan Johnston
#ifndef CAFE_H
#define CAFE_H

class Cafe {
public:
    Cafe() = default;
    Cafe(double cafePrice, double cafeLocation);

    void SetPrice(double cafePrice);
    void SetPlace(double cafeLocation);

    double GetPrice() const;
    double GetPlace() const;
    double GetProfit() const;
    int GetCustomerCount() const;

    void ServeCustomer();
    void Print() const;

private:
    double price = 0.0;
    double location = 0.0;
    double profit = 0.0;
    int customerCount = 0;
};

#endif
