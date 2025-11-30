#pragma once
#include <string>

class SensorConfig
{
        private:
        std::string id;
        std::string type;
        public:
        SensorConfig(const std::string& id, const std::string& type) : id(id), type(type){}
        void print() const

};
