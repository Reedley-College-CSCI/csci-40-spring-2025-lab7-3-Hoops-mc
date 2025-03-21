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

// Constants
const int MAX_DAYS = 31;

// Function Prototypes
void readTemperatures(TemperatureRecord tempRecord[], int& size); // TODO: Fix the parameters
void printTemperatures(const TemperatureRecord tempRecord[], int size);
TemperatureRecord findMin(const TemperatureRecord tempRecord[], int size);
TemperatureRecord findMax(const TemperatureRecord tempRecord[], int size);
double findAverage(const TemperatureRecord tempRecord[], int size);

int main() {
    // TODO: Step 2 - Declare an array of TemperatureRecord structs (MAX_DAYS size)
    TemperatureRecord tempRecord[MAX_DAYS];

    int size = 0;  // Actual number of records read

    // TODO: Step 3 - Call readTemperatures() to load data from file
    readTemperatures(tempRecord, size);

    // TODO: Step 4 - Print the temperatures
    printTemperatures(tempRecord, size);

    // TODO: Step 5 - Compute and display min, max, and average temperature
    
    TemperatureRecord minRecord = findMin(tempRecord, size);
    TemperatureRecord maxRecord = findMax(tempRecord, size);
    double averageTemp = findAverage(tempRecord, size);
                                                                                             
    cout << "\nTemperature Records\n"
        << "----------------------\n"
        << "Minimum Temperature: Day " << minRecord.day << ", " << minRecord.temp << " Celcius\n"
        << "Maximum Temperature: Day " << maxRecord.day << ", " << maxRecord.temp << " Celcius\n"
        << fixed << setprecision(2)
        << "Average Temperature: " << averageTemp << " Celcius\n";

    
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
void printTemperatures(const TemperatureRecord tempRecord[], int size)
{
    cout << "\nDay\tTemp\n";
    for (int i = 0; i < size; i++)
    {
        cout << tempRecord[i].day << "\t" << tempRecord[i].temp << endl;
    }
}

// TODO: Step 8 - Implement findMin()
// Return the TemperatureRecord with the lowest temperature
TemperatureRecord findMin(const TemperatureRecord tempRecord[], int size)
{
    TemperatureRecord minRecord = tempRecord[0];
    for (int i = 1; i < size; i++)
    {
        if (tempRecord[i].temp < minRecord.temp)
        {
            minRecord = tempRecord[i];
        }
    }
    return minRecord;
}

// TODO: Step 9 - Implement findMax()
// Return the TemperatureRecord with the highest temperature
TemperatureRecord findMax(const TemperatureRecord tempRecord[], int size)
{
    TemperatureRecord maxRecord = tempRecord[0];
    for (int i = 1; i < size; ++i)
    {
        if (tempRecord[i].temp > maxRecord.temp)
        {
            maxRecord = tempRecord[i];
        }

    }
    return maxRecord;
}

// TODO: Step 10 - Implement findAverage()
// Compute and return the average temperature
double findAverage(const TemperatureRecord tempRecord[], int size)
{
    if (size == 0)
    {
        return 0.0;
    }

    int total = 0;
    for (int i = 0; i < size; ++i)
    {
        total += tempRecord[i].temp;
    }

    return static_cast<double>(total) / size;
}
