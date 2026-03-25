#include "Volvo.h"

std::string Volvo::GetName() const { return "Volvo"; }
double Volvo::GetFuelCapacity() const { return 65.0; }
double Volvo::GetFuelConsumption() const { return 8.0; }
double Volvo::GetSpeed(Weather weather) const {
    switch (weather) {
    case Weather::Rain: return 85.0;
    case Weather::Sunny: return 120.0;
    case Weather::Snow: return 60.0;
    default: return 0.0;
    }
}