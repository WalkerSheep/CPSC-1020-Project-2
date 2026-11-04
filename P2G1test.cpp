// Group 1: Eric Nguyen, Walker Allen, Evan Johnston
#include "Cafe.h"
#include "Customer.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

double Location;
double Price;

//Enter Value for Customer
cout << "Enter a Customer location between 0 and 10 inclusive: ";
cin >> Location;
//Verify user is inputing valid location
while (Location < 0 || Location > 10) {
    cout << "Invalid Placement, please enter a number between 0 and 10 inclusive. \n";
    cin >> Location;
}
//Runs and prints Location Value
Customer CustomerOne(Location); 
cout << fixed << setprecision(2) << CustomerOne.GetLocation() << endl;

cout << "Enter the Cafe Price and Cafe Location";

Cafe CafeOne();

//Output starting values of customer

//Output starting values of Cafe
//cout << CafeOne.GetPrice() << CafeOne.GetLocation() << CafeOne.GetPrice() << CafeOne.GetProfit() << CafeOne.GetCustomerCount();

return 0;
}
