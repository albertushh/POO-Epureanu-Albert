#include "Circuit.h"
#include <iostream>
#include <algorithm>

Circuit::Circuit() : length(0), weather(Weather::Sunny) {}

Circuit::~Circuit() {
    for (Car* car : competitors) {
        delete car;
    }
}

void Circuit::SetLength(double trackLength) {
    length = trackLength;
}

void Circuit::SetWeather(Weather condition) {
    weather = condition;
}

void Circuit::AddCar(Car* car) {
    competitors.push_back(car);
}

void Circuit::Race() {
    finishedCars.clear();
    dnfCars.clear();

    for (Car* car : competitors) {
        double fuelNeeded = (length * car->GetFuelConsumption()) / 100.0;

        if (car->GetFuelCapacity() >= fuelNeeded) {
            double speed = car->GetSpeed(weather);
            double time = length / speed;
            finishedCars.push_back({ car->GetName(), time });
        }
        else {
            dnfCars.push_back(car->GetName());
        }
    }

    std::sort(finishedCars.begin(), finishedCars.end(),
        [](const RaceResult& a, const RaceResult& b) {
            return a.timeInHours < b.timeInHours;
        });
}

void Circuit::ShowFinalRanks() const {
    std::cout << "\n--- FINAL RANKS ---\n";
    for (size_t i = 0; i < finishedCars.size(); ++i) {
        std::cout << (i + 1) << ". " << finishedCars[i].carName
            << " - Time: " << finishedCars[i].timeInHours << " hours\n";
    }
}

void Circuit::ShowWhoDidNotFinish() const {
    std::cout << "\n--- DID NOT FINISH (Out of fuel) ---\n";
    if (dnfCars.empty()) {
        std::cout << "All cars finished successfully.\n";
    }
    else {
        for (const std::string& name : dnfCars) {
            std::cout << "- " << name << "\n";
        }
    }
    std::cout << "\n";
}