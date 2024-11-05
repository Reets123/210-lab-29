// Lab 29: Project Proposal, Pseudocode, & Mockup 
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

// Define a function to simulate traffic flow
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

        // Simulate random vehicle arrivals
        for (int i = 0; i < rand() % 5; i++) { // Random number of vehicles (0-4)
            Vehicle newVehicle = {"Car", time}; // Example vehicle type
            string intersectionKey = "Intersection" + to_string(rand() % 3); // Assume 3 intersections

            trafficMap[intersectionKey].push_back(newVehicle);
            cout << " - A new vehicle arrived at " << intersectionKey << " at time " << time << endl;
        }

        cout << endl; // For spacing
    }
}

// Define main function
int main() {
    srand(static_cast<unsigned>(time(0))); // Seed for random generation

    // Initialize a map to store traffic information for intersections
    map<string, list<Vehicle>> trafficMap;

    // Open an external file to read initial data about intersections (if required)
    ifstream inputFile("traffic_data.csv");
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        
        return 1; // Exit failure
    }

    // Example: Populate trafficMap with initial intersections (requires file processing)
    trafficMap["Intersection1"] = {};
    trafficMap["Intersection2"] = {};
    trafficMap["Intersection3"] = {};
    
    inputFile.close();

    // Begin a time-based simulation for traffic flow
    simulateTraffic(trafficMap, 25); // Simulate for 25 time periods
    
    return 0; 
}