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

            // Simulate traffic light change (