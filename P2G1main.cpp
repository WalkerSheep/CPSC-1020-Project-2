
// Group 1: Eric Nguyen, Walker Allen, Evan Johnston
#include "Cafe.h"     // Lets us create cafes and use Cafe functions
#include "Customer.h" // Lets us create customers and calculate cafe scores
#include <iostream>   // Lets us use cin and cout
#include <iomanip>    // Lets us print money with 2 decimal places
#include <stdexcept>  // Lets us use exceptions and error messages
#include <string>     // Lets us store text using string
#include <sstream>    // Lets us turn typed text into a number
#include <climits>    // Gives us INT_MAX for the trial limit
#include <cstdlib>    // Lets us use rand() and srand()
#include <ctime>      // Lets us use time(0) for random numbers
using namespace std;

// ReadNumber: Reads numbers as text so letters will not break cin.
double ReadNumber()
{
    string input;

    // Read what the user types as text
    if (cin >> input)
    {
        stringstream converter(input);
        double number = 0;
        char extra;

        // Try to turn the text into a number
        if (converter >> number)
        {
            // Check for extra characters
            if (converter >> extra)
            {
                throw runtime_error("Please enter a valid number.");
            }

            return number;
        }

        throw runtime_error("Please enter a valid number.");
    }

    // Stop if there is no more input
    throw logic_error("No more input was provided.");
}

// GetNumberOfCafes: Gets how many cafes a company owns.
int GetNumberOfCafes(char company)
{
    while (true)
    {
        try
        {
            cout << "How many cafes for Company " << company << " (1-10)? ";
            double count = ReadNumber();

            // Make sure the count is between 1 and 10
            if (count < 1 || count > 10)
            {
                throw runtime_error("Enter a number between 1 and 10.");
            }

            // Make sure the count is a whole number
            if (count != (int)count)
            {
                throw runtime_error("Please enter a whole number.");
            }

            return (int)count;
        }
        catch (runtime_error& error)
        {
            cout << error.what() << endl;
        }
    }
}

// GetCafeInformation: Gets the location and price of each cafe.
void GetCafeInformation(Cafe cafes[], int count, char company)
{
    for (int i = 0; i < count; i++)
    {
        double location = 0;
        double price = 0;
        bool validLocation = false;
        bool validPrice = false;

        cout << "\nCafe " << company << i + 1 << endl;

        // Get the location first, like the class example
        while (validLocation == false)
        {
            try
            {
                cout << "Enter location (0-10): ";
                location = ReadNumber();

                if (location >= 0 && location <= 10)
                {
                    validLocation = true;
                }
                else
                {
                    throw runtime_error("Enter a location from 0 to 10.");
                }
            }
            catch (runtime_error& error)
            {
                cout << error.what() << endl;
            }
        }

        // Get the coffee price
        while (validPrice == false)
        {
            try
            {
                cout << "Enter coffee price (0-6): ";
                price = ReadNumber();

                if (price >= 0 && price <= 6)
                {
                    validPrice = true;
                }
                else
                {
                    throw runtime_error("Enter a price from 0 to 6.");
                }
            }
            catch (runtime_error& error)
            {
                cout << error.what() << endl;
            }
        }

        // Save the values in the Cafe object
        cafes[i].SetLocation(location);
        cafes[i].SetPrice(price);
    }
}

// GetNumberOfTrials: Gets how many customers to simulate.
int GetNumberOfTrials()
{
    while (true)
    {
        try
        {
            cout << "\nHow many simulation trials? ";
            double trials = ReadNumber();

            // Trials must be a positive number
            if (trials < 1 || trials > INT_MAX)
            {
                throw runtime_error("Enter a positive number of trials.");
            }

            // Trials must be a whole number
            if (trials != (int)trials)
            {
                throw runtime_error("Please enter a whole number.");
            }

            return (int)trials;
        }
        catch (runtime_error& error)
        {
            cout << error.what() << endl;
        }
    }
}

// RunSimulation: Creates customers and decides which cafe they visit.
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

        // Get the scores for Company A
        for (int i = 0; i < numA; i++)
        {
            scoresA[i] = customer.CalculateScore(cafesA[i]);
            totalScore += scoresA[i];
        }

        // Get the scores for Company B
        for (int i = 0; i < numB; i++)
        {
            scoresB[i] = customer.CalculateScore(cafesB[i]);
            totalScore += scoresB[i];
        }

        // Make sure probabilities can be calculated
        if (totalScore <= 0)
        {
            cout << "Cannot calculate cafe probabilities." << endl;
            return false;
        }

        // Find the cafe with the highest probability
        Cafe* chosenCafe = nullptr;
        double highestProbability = -1;
        int ties = 0;

        // Check Company A cafes
        for (int i = 0; i < numA; i++)
        {
            double probability = scoresA[i] / totalScore;

            if (probability > highestProbability)
            {
                highestProbability = probability;
                chosenCafe = &cafesA[i];
                ties = 1;
            }
            else if (probability == highestProbability)
            {
                // Randomly choose when cafes have the same probability
                ties++;

                if (rand() % ties == 0)
                {
                    chosenCafe = &cafesA[i];
                }
            }
        }

        // Check Company B cafes
        for (int i = 0; i < numB; i++)
        {
            double probability = scoresB[i] / totalScore;

            if (probability > highestProbability)
            {
                highestProbability = probability;
                chosenCafe = &cafesB[i];
                ties = 1;
            }
            else if (probability == highestProbability)
            {
                // Randomly choose when cafes have the same probability
                ties++;

                if (rand() % ties == 0)
                {
                    chosenCafe = &cafesB[i];
                }
            }
        }

        // Serve the customer at the winning cafe
        chosenCafe->ServeCustomer();

        // Store which cafe the customer visited
        customer.SetVisitedCafe(chosenCafe);
    }

    return true;
}

// PrintResults: Prints the profit and customer count for each cafe.
void PrintResults(Cafe cafes[], int count, char company, int trials)
{
    cout << "\nCompany " << company << " Results:" << endl;
    cout << fixed << setprecision(2);

    for (int i = 0; i < count; i++)
    {
        // Calculate the cafe's average profit per trial
        double averageProfit = cafes[i].GetProfit() / trials;

        cout << "\nCafe " << company << i + 1 << endl;
        cout << "Price: $" << cafes[i].GetPrice() << endl;
        cout << "Location: " << cafes[i].GetLocation() << " km" << endl;
        cout << "Customers: " << cafes[i].GetCustomerCount() << endl;
        cout << "Total Profit: $" << cafes[i].GetProfit() << endl;
        cout << "Average Profit per Trial: $" << averageProfit << endl;
    }
}

// main: Gets user input, runs the simulation, and prints results.
int main()
{
    try
    {
        // Ask how many trials to run first
        int trials = GetNumberOfTrials();

        // Ask how many cafes each company owns
        int numA = GetNumberOfCafes('A');
        int numB = GetNumberOfCafes('B');

        // Create arrays for both companies
        Cafe cafesA[10];
        Cafe cafesB[10];

        // Get the location and price of each cafe
        GetCafeInformation(cafesA, numA, 'A');
        GetCafeInformation(cafesB, numB, 'B');

        // Start the random number generator
        srand(time(0));

        cout << "\nRunning " << trials << " trials..." << endl;

        // Run the simulation and stop if it fails
        if (RunSimulation(cafesA, numA, cafesB, numB, trials) == false)
        {
            return 1;
        }

        // Print results for both companies
        PrintResults(cafesA, numA, 'A', trials);
        PrintResults(cafesB, numB, 'B', trials);

        // Calculate Company A's total average profit
        double myTotalProfit = 0;

        for (int i = 0; i < numA; i++)
        {
            myTotalProfit += cafesA[i].GetProfit() / trials;
        }

        cout << "\nMy Total Profit: $" << fixed << setprecision(2)
             << myTotalProfit << endl;

        // Add up all the customers served
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

        // Make sure every trial served one customer
        if (totalCustomers != trials)
        {
            cout << "Error: Not every trial served a customer." << endl;
            return 1;
        }

        cout << "Simulation Complete!" << endl;
        return 0;
    }
    catch (logic_error& error)
    {
        // Stop if the program runs out of input
        cout << error.what() << endl;
        return 1;
    }
}
