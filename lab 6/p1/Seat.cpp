#include "Seat.h"

std::string Seat::GetName() const { return "Seat"; }
double Seat::GetFuelCapacity() const { return 45.0; }
double Seat::GetFuelConsumption() const { return 6.5; }
double Seat::GetSpeed(Weather weather) const {
    switch (weather) {
    case Weather::Rain: return 75.0;
    case Weather::Sunny: return 110.0;
    case Weather::Snow: return 50.0;
    default: return 0.0;
    }
}