#include <iostream>
#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>
#include <SensorConfig.h>
using json = nlohmann::json;

int main()
{
    std::cout << "hello world++++" << std::endl;

    SensorConfig sensor(
        "sensor_1",
        "Temperature Sensor",
        Type::Analog,
        75.0,
        65.0,
        85.0,
        55.0
    );

    sensor.print();

    std::cout << "hello ubuntu" << std::endl;



    return 0;
}