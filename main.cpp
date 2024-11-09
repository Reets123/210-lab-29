// Lab 31: Beta Release
// COMSC-210 - Ibrahim Alatig 

#include <iostream>
#include <map>
#include <array>
#include <list>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

// Define a struct for Vehicle
struct Vehicle {
    string type; // E.g., "Car", "Truck", "Bus"
    int arrivalTime; // Time when the vehicle arrives
};

// Function to load initial vehicle data from file
void loadVehiclesFromFile(const string& filename, map<string, list<Vehicle>>& trafficMap) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return; // Exit function
    }

    string intersection;
    while (inputFile >> intersection) {
        Vehicle vehicle;
        inputFile >> vehicle.type >> vehicle.arrivalTime;  // Read type and arrival time
        trafficMap[intersection].push_back(vehicle);
    }

    inputFile.close();
}

// Function to simulate traffic flow
void simulateTraffic(map<string, list<Vehicle>>& trafficMap, int timeIntervals) {
    for (int time = 0; time < timeIntervals; time++) {
        cout << "Time Period: " << time << endl;

        // Iterate through each intersection in the map
        for (auto& intersection : trafficMap) {
            // Display current vehicles at the intersection
            cout << "Intersection: " << intersection.first << endl;
            for (const auto& vehicle : intersection.second) {
                cout << " - " << vehicle.type << " arrived at " << vehicle.arrivalTime << endl;
            }

            // Simulate traffic light change (simple logic)
            if (time % 5 == 0) { // Every 5 time intervals
                cout << " - Traffic light changes at " << intersection.first << endl;

                // Allow vehicles to depart based on a random chance
                while (!intersection.second.empty()) {
                    intersection.second.pop_front(); // Vehicle departs
                    cout << " - A vehicle has departed from " << intersection.first << endl;
                }
            }
        }

        cout << endl; // For spacing
    }
}

// Define main function
int main() {
    srand(static_cast<unsigned>(time(0))); // Seed for random generation

    // Initialize a map to store traffic information for intersections
    map<string, list<Vehicle>> trafficMap;

    // Load initial data from the file
    loadVehiclesFromFile("traffic_data.txt", trafficMap);

    // Begin a time-based simulation for traffic flow
    simulateTraffic(trafficMap, 25); // Simulate for 25 time periods

    return 0; 
}