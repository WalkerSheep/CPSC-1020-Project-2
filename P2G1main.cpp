
 // Group 1: Eric Nguyen, Walker Allen, Evan Johnston
#include "Cafe.h"
#include "Customer.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <climits>
#include <cstdlib>
#include <ctime>
using namespace std;

// Asks for a number and makes sure it is valid
double GetNumber(string question, double lowest, double highest, bool wholeNumber)
{
    while (true)
    {
        string input;
        cout << question;

        if (!getline(cin, input))
        {
            cout << "No more input." << endl;
            exit(1);
        }

        try
        {
            size_t used = 0;
            double number = stod(input, &used);

            if (used != input.length())
            {
                throw runtime_error("Please enter a valid number.");
            }

            if (!(number >= lowest && number <= highest))
            {
                throw runtime_error("Number is outside the allowed range.");
            }

            if (wholeNumber && number != (int)number)
            {
                throw runtime_error("Please enter a whole number.");
            }

            return number;
        }
        catch (runtime_error& error)
        {
            cout << error.what() << endl;
        }
        catch (exception& error)
        {
            cout << "Please enter a valid number." << endl;
        }
    }
}

// Gets the number of cafes for a company
int GetNumberOfCafes(char company)
{
    string question = "How many cafes for Company ";
    question += company;
    question += " (1-10)? ";

    return (int)GetNumber(question, 1, 10, true);
}

// Gets the price and location of each cafe
void GetCafeInformation(Cafe cafes[], int count, char company)
{
    for (int i = 0; i < count; i++)
    {
        cout << "\nCafe " << company << i + 1 << endl;

        // Keeping prices in this range prevents negative probability scores
        double price = GetNumber("Enter coffee price (0-6): ", 0, 6, false);
        double location = GetNumber("Enter location (0-10): ", 0, 10, false);

        cafes[i].SetPrice(price);
        cafes[i].SetLocation(location);
    }
}

// Gets the number of trials
int GetNumberOfTrials()
{
    return (int)GetNumber("\nHow many simulation trials? ", 1, INT_MAX, true);
}

// Runs one customer visit per trial
bool RunSimulation(Cafe cafesA[], int numA, Cafe cafesB[], int numB, int trials)
{
    for (int t = 0; t < trials; t++)
    {
        // Generate a random customer location
        double location = ((rand() % 10000) + 0.5) / 1000.0;
        Customer customer(location);

        double scoresA[10];
        double scoresB[10];
        double totalScore = 0;

        // Calculate scores for Company A
        for (int i = 0; i < numA; i++)
        {
            scoresA[i] = customer.CalculateScore(cafesA[i]);
            totalScore += scoresA[i];
        }

        // Calculate scores for Company B
        for (int i = 0; i < numB; i++)
        {
            scoresB[i] = customer.CalculateScore(cafesB[i]);
            totalScore += scoresB[i];
        }

        if (totalScore <= 0)
        {
            cout << "Cannot calculate cafe probabilities." << endl;
            return false;
        }

        // Find the cafe with the highest probability
        double highestProbability = -1;
        Cafe* chosenCafe = nullptr;

        // Check Company A
        for (int i = 0; i < numA; i++)
        {
            double probability = scoresA[i] / totalScore;

            if (probability > highestProbability)
            {
                highestProbability = probability;
                chosenCafe = &cafesA[i];
            }
        }

        // Check Company B
        for (int i = 0; i < numB; i++)
        {
            double probability = scoresB[i] / totalScore;

            if (probability > highestProbability)
            {
                highestProbability = probability;
                chosenCafe = &cafesB[i];
            }
        }

        // Serve the customer at the winning cafe
        chosenCafe->ServeCustomer();
        customer.SetVisitedCafe(chosenCafe);
    }

    return true;
}

// Prints the results for one company
void PrintResults(Cafe cafes[], int count, char company, int trials)
{
    cout << "\nCompany " << company << " Results:" << endl;
    cout << fixed << setprecision(2);

    for (int i = 0; i < count; i++)
    {
        double averageProfit = cafes[i].GetProfit() / trials;

        cout << "\nCafe " << company << i + 1 << endl;
        cout << "Price: $" << cafes[i].GetPrice() << endl;
        cout << "Location: " << cafes[i].GetLocation() << " km" << endl;
        cout << "Customers: " << cafes[i].GetCustomerCount() << endl;
        cout << "Total Profit: $" << cafes[i].GetProfit() << endl;
        cout << "Average Profit per Trial: $" << averageProfit << endl;
    }
}

int main()
{
    int numA = GetNumberOfCafes('A');
    int numB = GetNumberOfCafes('B');

    Cafe cafesA[10];
    Cafe cafesB[10];

    GetCafeInformation(cafesA, numA, 'A');
    GetCafeInformation(cafesB, numB, 'B');

    int trials = GetNumberOfTrials();

    srand(time(0));

    cout << "\nRunning " << trials << " trials..." << endl;

    RunSimulation(cafesA, numA, cafesB, numB, trials);

    // Print results
    PrintResults(cafesA, numA, 'A', trials);
    PrintResults(cafesB, numB, 'B', trials);

    // Count all customers
    int totalCustomers = 0;

    for (int i = 0; i < numA; i++)
    {
        totalCustomers += cafesA[i].GetCustomerCount();
    }

    for (int i = 0; i < numB; i++)
    {
        totalCustomers += cafesB[i].GetCustomerCount();
    }

    cout << "\nTotal Customers Served: " << totalCustomers << endl;
    cout << "Simulation Complete!" << endl;

    return 0;
}
