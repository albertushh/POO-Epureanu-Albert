#pragma once
#include "Weather.h"
#include "Car.h"
#include <vector>
#include <string>

struct RaceResult {
    std::string carName;
    double timeInHours;
};

class Circuit {
private:
    double length;
    Weather weather;
    std::vector<Car*> competitors;
    std::vector<RaceResult> finishedCars;
    std::vector<std::string> dnfCars;

public:
    Circuit();
    ~Circuit();

    void SetLength(double trackLength);
    void SetWeather(Weather condition);
    void AddCar(Car* car);

    void Race();
    void ShowFinalRanks() const;
    void ShowWhoDidNotFinish() const;
};