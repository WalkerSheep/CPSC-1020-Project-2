
 // Group 1: Eric Nguyen, Walker Allen, Evan Johnston
#include "Cafe.h"
#include "Customer.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Enter a customer location
    double customerLocation;

    cout << "Enter a customer location between 0 and 10: ";
    cin >> customerLocation;

    while (customerLocation < 0 || customerLocation > 10)
    {
        cout << "Invalid location. Enter a number between 0 and 10: ";
        cin >> customerLocation;
    }

    Customer CustomerOne(customerLocation);

    cout << fixed << setprecision(2);
    cout << "Customer Location: " << CustomerOne.GetLocation() << endl;

    // Enter a cafe price and location
    double cafePrice;
    double cafeLocation;

    cout << "Enter the Cafe price: ";
    cin >> cafePrice;

    cout << "Enter the Cafe location: ";
    cin >> cafeLocation;

    while (cafePrice < 0 || cafeLocation < 0 || cafeLocation > 10)
    {
        cout << "Invalid input. Enter the Cafe price: ";
        cin >> cafePrice;

        cout << "Enter the Cafe location: ";
        cin >> cafeLocation;
    }

    Cafe CafeOne(cafePrice, cafeLocation);

    cout << "Cafe Price: $" << CafeOne.GetPrice() << endl;
    cout << "Cafe Location: " << CafeOne.GetLocation() << endl;

    // Calculate the score for the cafe
    cout << "Cafe Score: " << CustomerOne.CalculateScore(CafeOne) << endl;

    // Test ServeCustomer
    int times;

    cout << "How many times would you like to call ServeCustomer? ";
    cin >> times;

    while (times < 0)
    {
        cout << "Enter a number greater than or equal to 0: ";
        cin >> times;
    }

    for (int i = 0; i < times; i++)
    {
        CafeOne.ServeCustomer();
    }

    cout << "\nCafe Results:" << endl;
    CafeOne.Print();

    // Test Cafe functions
    cout << "\nTesting Cafe Functions:" << endl;

    // Default constructor
    Cafe defaultCafe;

    cout << "Default Price: " << defaultCafe.GetPrice() << endl;
    cout << "Default Location: " << defaultCafe.GetLocation() << endl;
    cout << "Default Profit: " << defaultCafe.GetProfit() << endl;
    cout << "Default Customer Count: " << defaultCafe.GetCustomerCount() << endl;

    // Setters and getters
    defaultCafe.SetPrice(4);
    defaultCafe.SetLocation(7);

    cout << "Updated Price: " << defaultCafe.GetPrice() << endl;
    cout << "Updated Location: " << defaultCafe.GetLocation() << endl;

    // Serve three customers
    Cafe salesCafe(5, 3);

    salesCafe.ServeCustomer();
    salesCafe.ServeCustomer();
    salesCafe.ServeCustomer();

    cout << "\nAfter serving three customers at $5 each:" << endl;
    salesCafe.Print();

    // Change the coffee price
    salesCafe.SetPrice(6);
    salesCafe.ServeCustomer();

    cout << "\nAfter changing the price to $6 and serving another customer:" << endl;
    salesCafe.Print();

    // Test Customer functions
    cout << "\nTesting Customer Functions:" << endl;

    // Default constructor
    Customer defaultCustomer;

    cout << "Default Location: " << defaultCustomer.GetLocation() << endl;
    cout << boolalpha;
    cout << "No Visited Cafe: " << (defaultCustomer.GetVisitedCafe() == nullptr) << endl;

    // Setters and getters
    defaultCustomer.SetLocation(8);

    cout << "Updated Customer Location: " << defaultCustomer.GetLocation() << endl;

    // Set visited cafe
    defaultCustomer.SetVisitedCafe(&salesCafe);

    cout << "Visited Cafe Price: $" << defaultCustomer.GetVisitedCafe()->GetPrice() << endl;
    cout << "Visited Cafe Location: " << defaultCustomer.GetVisitedCafe()->GetLocation() << endl;

    // Clear visited cafe
    defaultCustomer.SetVisitedCafe(nullptr);

    cout << "Visited Cafe Cleared: " << (defaultCustomer.GetVisitedCafe() == nullptr) << endl;

    // Test CalculateScore with two cafes
    cout << "\nTesting CalculateScore:" << endl;

    Customer testCustomer(3);

    Cafe cafeA(5, 7);
    Cafe cafeB(4, 2);

    cout << "Cafe A Score (Expected 9): " << testCustomer.CalculateScore(cafeA) << endl;
    cout << "Cafe B Score (Expected 15): " << testCustomer.CalculateScore(cafeB) << endl;

    // Test distance from the other direction
    Customer anotherCustomer(7);
    Cafe leftCafe(5, 3);

    cout << "Reverse Distance Score (Expected 9): " << anotherCustomer.CalculateScore(leftCafe) << endl;

    // Test copy constructor
    cout << "\nTesting Copy Constructor:" << endl;

    testCustomer.SetVisitedCafe(&cafeA);

    Customer copiedCustomer(testCustomer);

    cout << "Original Location: " << testCustomer.GetLocation() << endl;
    cout << "Copied Location: " << copiedCustomer.GetLocation() << endl;
    cout << "Same Visited Cafe: " << (copiedCustomer.GetVisitedCafe() == testCustomer.GetVisitedCafe()) << endl;

    // Change copied customer
    copiedCustomer.SetLocation(6);

    cout << "Original Location After Change: " << testCustomer.GetLocation() << endl;
    cout << "Copied Location After Change: " << copiedCustomer.GetLocation() << endl;

    // Test copy assignment operator
    cout << "\nTesting Copy Assignment Operator:" << endl;

    Customer assignedCustomer;

    assignedCustomer = testCustomer;

    cout << "Assigned Location: " << assignedCustomer.GetLocation() << endl;
    cout << "Same Visited Cafe: " << (assignedCustomer.GetVisitedCafe() == testCustomer.GetVisitedCafe()) << endl;

    // Test self-assignment
    assignedCustomer = assignedCustomer;

    cout << "Location After Self-Assignment: " << assignedCustomer.GetLocation() << endl;

    // Test destructor
    cout << "\nTesting Destructor:" << endl;

    {
        Customer temporaryCustomer(2);
        temporaryCustomer.SetVisitedCafe(&cafeA);

        cout << "Temporary Customer Location: " << temporaryCustomer.GetLocation() << endl;
    }

    cout << "Cafe A Price After Destructor: $" << cafeA.GetPrice() << endl;
    cout << "Cafe A Location After Destructor: " << cafeA.GetLocation() << endl;

    cout << "\nTesting Complete!" << endl;

    return 0;
}
