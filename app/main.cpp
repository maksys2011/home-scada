#include <iostream>
#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>
#include "SensorConfig.hpp"
#include "ActuatorConfig.hpp"
#include "Actuator.hpp"
#include "Sensor.hpp"
#include "RandomSource.hpp"
#include "Logger.hpp"
#include "SensorManager.hpp"
#include "SmoothRandomSource.hpp"
using json = nlohmann::json;

int main() {

    Logger log("../logs/events.log");
    SensorConfig cfg;
    const std::string filePath("/home/maksys2011/home-scada/configTest.json/SensorConfig.json");
    cfg.fromJson(filePath);
    SensorState state(cfg, &log);
    SmothRandomSource  sours(22.0,0.2,15,30);
    

    for(int i = 0; i < 100; i++){
        state.processValue(sours.readValue());
        std::cout << sours.readValue() << std::endl;
    }




}
