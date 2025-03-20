//Octavio Moreno

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


// TODO: Step 1 - Define the struct TemperatureRecord
// It should contain two integer fields: day and temperature.
struct TemperatureRecord {
    int day;
    int temp;
};

//Declared array of TemperatureRecord in global section
TemperatureRecord tempRecord;

// Constants
const int MAX_DAYS = 31;

// Function Prototypes
void readTemperatures(TemperatureRecord tempRecord[], int& size); // TODO: Fix the parameters
void printTemperatures(const ???);
TemperatureRecord findMin(const ???);
TemperatureRecord findMax(const ???);
double findAverage(const ???);

int main() {
    // TODO: Step 2 - Declare an array of TemperatureRecord structs (MAX_DAYS size)
    TemperatureRecord tempRecord[MAX_DAYS];

    int size = 0;  // Actual number of records read

    // TODO: Step 3 - Call readTemperatures() to load data from file
  

    // TODO: Step 4 - Print the temperatures
  

    // TODO: Step 5 - Compute and display min, max, and average temperature

    return 0;
}

// TODO: Step 6 - Implement readTemperatures()
// Read from "temps.txt" and store data in the array
void readTemperatures(TemperatureRecord tempRecord[], int& size)
{
    ifstream inFile("temps.txt");

    if (!inFile)
    {
        cout << "Unable to open file. Please try again.";
        return;
    }

    //read data from file until it reaches last day or until there is no more data to be read
    while (size < MAX_DAYS && inFile >> tempRecord[size].day >> tempRecord[size].temp)
    {
        size++;
    }

        inFile.close();
}

// TODO: Step 7 - Implement printTemperatures()
// Print all stored temperatures in a formatted table


// TODO: Step 8 - Implement findMin()
// Return the TemperatureRecord with the lowest temperature


// TODO: Step 9 - Implement findMax()
// Return the TemperatureRecord with the highest temperature


// TODO: Step 10 - Implement findAverage()
// Compute and return the average temperature
