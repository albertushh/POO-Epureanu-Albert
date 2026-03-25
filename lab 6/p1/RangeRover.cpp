#include "RangeRover.h"

std::string RangeRover::GetName() const { return "RangeRover"; }
double RangeRover::GetFuelCapacity() const { return 85.0; }
double RangeRover::GetFuelConsumption() const { return 12.0; }
double RangeRover::GetSpeed(Weather weather) const {
    switch (weather) {
    case Weather::Rain: return 110.0;
    case Weather::Sunny: return 130.0;
    case Weather::Snow: return 95.0;
    default: return 0.0;
    }
}