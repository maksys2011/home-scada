#include <iostream>
#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>
#include "SensorConfig.hpp"
#include "ActuatorConfig.hpp"
#include "Actuator.hpp"
using json = nlohmann::json;

int main()
{
    std::string file = "../configTest.json/SensorConfig.json";
    SensorConfig s;
    s.fromJson(file);
    s.print();

    std::cout << "-----------------" << std::endl;

    std::string file2 = "../configTest.json/ActuatorConfig.json";
    ActuatorConfig a;
    a.fromJson(file2);
    a.print();
    std::cout << std::endl;

    Actuator motor(a);
    motor.print();

    std::cout << "TEST 4" << std::endl;

    
    



    return 0;
}