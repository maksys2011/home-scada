#include <Enum.h>

Type ParseType(const std::string &typeStr)
{
    if (typeStr == "Analog")
        return Type::Analog;
    else if (typeStr == "Digital")
        return Type::Digital;
    else if (typeStr == "Counter")
        return Type::Counter;
    else
        throw   ("Invalid type string: " + typeStr);
}

std::string TypeToString(Type type)
{
    switch (type)
    {
        case Type::Analog:
            return "Analog";
        case Type::Digital:
            return "Digital";
        case Type::Counter:
            return "Counter";
        default:
            return "Unknown";
    }
}