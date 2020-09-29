#include <bits/stdc++.h>
int descendingOrder(const void * a, const void * b) {
    return (*(int*)a > *(int*)b);
}
int main() {
    std::ostream::sync_with_stdio(false);
    int numberOfTests, buildingSize, elevatorCapacity, peopleLeft, populationSize, destinations[50000], energySpent, onboardPassengers = 0, nextTour[50000], currentPosition = 0;

    std::cin >> numberOfTests;
    for (int i = 0; i < numberOfTests; ++i) {
        energySpent = 0;
        std::cin >> buildingSize >> elevatorCapacity >> populationSize;
        peopleLeft = populationSize;
        for (int j = 0; j < populationSize; ++j) {
            std::cin >> destinations[j];
        }
        // Sorting destinations...
        qsort(destinations, populationSize, sizeof(int), descendingOrder);
        // OK! Calculating...
        while (peopleLeft > 0) {
            // New passengers enter the elevator
            int emptySpace = elevatorCapacity - onboardPassengers;
            for (int j = 0; j < std::min(emptySpace,peopleLeft); ++j) {
                nextTour[j] = destinations[peopleLeft - 1 - j];
            }
            peopleLeft -= emptySpace;
            onboardPassengers += emptySpace;
            // Elevator leave ground floor
            for (int j = 0; j < onboardPassengers; ++j) {
                // The elevator goes to the nearest destination
                energySpent += std::abs(currentPosition - nextTour[j]);
                currentPosition = nextTour[j];
                nextTour[j] = 0;
            }
            onboardPassengers = 0;
            // Elevator returns to ground floor
            energySpent += currentPosition;
            currentPosition = 0;
        }
        std::cout << energySpent << std::endl;
    }
    return 0;
}
