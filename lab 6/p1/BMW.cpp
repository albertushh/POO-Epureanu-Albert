#include "BMW.h"

std::string BMW::GetName() const { return "BMW"; }
double BMW::GetFuelCapacity() const { return 60.0; }
double BMW::GetFuelConsumption() const { return 9.5; }
double BMW::GetSpeed(Weather weather) const {
    switch (weather) {
    case Weather::Rain: return 100.0;
    case Weather::Sunny: return 140.0;
    case Weather::Snow: return 75.0;
    default: return 0.0;
    }
}