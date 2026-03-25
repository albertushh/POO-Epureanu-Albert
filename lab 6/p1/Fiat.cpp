#include "Fiat.h"

std::string Fiat::GetName() const { return "Fiat"; }
double Fiat::GetFuelCapacity() const { return 4.0; }
double Fiat::GetFuelConsumption() const { return 5.5; }
double Fiat::GetSpeed(Weather weather) const {
    switch (weather) {
    case Weather::Rain: return 60.0;
    case Weather::Sunny: return 90.0;
    case Weather::Snow: return 45.0;
    default: return 0.0;
    }
}