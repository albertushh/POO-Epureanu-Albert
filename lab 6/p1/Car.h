#pragma once
#include "Weather.h"
#include <string>

class Car {
public:
    virtual ~Car() = default;

    virtual std::string GetName() const = 0;
    virtual double GetFuelCapacity() const = 0;
    virtual double GetFuelConsumption() const = 0;
    virtual double GetSpeed(Weather weather) const = 0;
};