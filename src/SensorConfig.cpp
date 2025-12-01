#include <SensorConfig.h>
#include <iostream>

SensorConfig::SensorConfig(const std::string &id, 
                            const std::string &name, 
                            Type type, 
                            double warnHigh, 
                            double warnLow, 
                            double alarmHigh, 
                            double alarmLow)
    : id_(id),
      name_(name),
      type_(type),
      warnHigh_(warnHigh),
      warnLow_(warnLow),
      alarmHigh_(alarmHigh),
      alarmLow_(alarmLow)
      {}

SensorConfig::SensorConfig(const nlohmann::json &j)
      {

        id_ = j.at("id").get<std::string>();
        name_ = j.at("name").get<std::string>();
        type_ = ParseType(j.at("type").get<std::string>());
        warnHigh_ = j.at("warnHigh").get<double>();
        warnLow_ = j.at("warnLow").get<double>();
        alarmHigh_ = j.at("alarmHigh").get<double>();
        alarmLow_ = j.at("alarmLow").get<double>();
      }

bool SensorConfig::validate() const
{
    return alarmLow_ <= warnLow_ && warnLow_ <= warnHigh_ && warnHigh_ <= alarmHigh_;
}

void SensorConfig::print() const
{
    std::cout << "SensorConfig {" << std::endl;
    std::cout << "  id: " << id_ << std::endl;
    std::cout << "  name: " << name_ << std::endl;
    std::cout << "  type: ";
    std::cout << TypeToString(type_) << std::endl;
    std::cout << "  warnHigh: " << warnHigh_ << std::endl;
    std::cout << "  warnLow: " << warnLow_ << std::endl;
    std::cout << "  alarmHigh: " << alarmHigh_ << std::endl;
    std::cout << "  alarmLow: " << alarmLow_ << std::endl;
    std::cout << "}" << std::endl;
}
