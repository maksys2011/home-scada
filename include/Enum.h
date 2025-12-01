#pragma once
#include <string>
#include <stdexcept>

enum class Type
{
    Analog,
    Digital,
    Counter
};

Type ParseType(const std::string &typeStr);

std::string TypeToString(Type type);

