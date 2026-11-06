
// Group 1: Eric Nguyen, Walker Allen, Evan Johnston
#include "Cafe.h"
#include "Customer.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

double customerLocation;

//Enter Value for Customer
cout << "Enter a Customer location between 0 and 10 inclusive: ";
cin >> customerLocation;
//Verify user is inputing valid location
while (customerLocation < 0 || customerLocation > 10) {
    cout << "Invalid Placement, please enter a number between 0 and 10 inclusive. \n";
    cin >> customerLocation;
}
//Runs and prints Location Value
Customer CustomerOne(customerLocation); 
cout << "Location of Customer: " << fixed << setprecision(2) << CustomerOne.GetLocation() << endl;


//Cafe test values
double cafePrice;
double cafeLocation;

//Recieves input from user for cafePrice and cafeLocation
cout << "Enter the Cafe Price and Cafe Location: ";


cin >> cafePrice >> cafeLocation;

Cafe CafeOne(cafeLocation, cafePrice);
cout << "Cafe Location" << CafeOne.GetLocation << endl << "Price: " << CafeOne.GetPrice;

return 0;
}
