#pragma once
#include <string>
#include <stdexcept>

enum class SensorType
{
    Analog,
    Digital,
    Counter
};

enum class ActuatorType
{
    Relay, 
    PWM, 
    DigitalOut, 
    AnalogOut
};

SensorType ParseSensorType(const std::string &typeStr);

std::string SensorTypeToString(const SensorType type);

ActuatorType ParseActuatorType(const std::string &typeStr);

std::string ActuatorTypeToString(ActuatorType type);