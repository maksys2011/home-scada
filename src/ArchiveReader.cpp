#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
#include "ArchiveReader.hpp"
#include "Enum.hpp"

ArchiveReader::ArchiveReader(const std::string &path)
    : path_(path)
{}

std::vector<ArchiveRecord> ArchiveReader::readAll() const
{
    std::vector<ArchiveRecord>records;

    std::ifstream file(path_);
    if(!file.is_open()){
        std::cerr << "ArchiveReader cannot open file" << std::endl;
        return records;
    }

    std::string line;
    while(std::getline(file, line)){

        if(line.empty()) continue;

        std::stringstream ss(line);
        std::string token;

        try
        {
            //1. Time
            std::getline(ss, token, ';');
            std::time_t timestap = static_cast<time_t>(std::stoll(token));

            // 2. SensorID
            std::getline(ss, token, ';');
            std::string sensorId = token;

            // 3. SensorName
            std::getline(ss, token, ';');
            std::string sensorName = token;

            // 4. Value
            std::getline(ss, token, ';');
            double value = std::stoll(token);

            // 5. State
            std::getline(ss, token, ';');
            State state = ParseState(token);

            ArchiveRecord record(
                timestap,
                sensorId,
                sensorName,
                value,
                state
            );

            records.push_back(record);
        }
        catch(const std::exception& e)
        {
            std::cerr << "ArchiveReader: skip bad line: " << line << std::endl;
            continue;
        }
    
    }
    
    return records;
}
