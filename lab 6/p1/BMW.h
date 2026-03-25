#pragma once
#include "Car.h"

class BMW : public Car {
public:
    std::string GetName() const override;
    double GetFuelCapacity() const override;
    double GetFuelConsumption() const override;
    double GetSpeed(Weather weather) const override;
};