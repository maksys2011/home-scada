#pragma once
#include <Source.hpp>
#include <random>

class SmothRandomSource : public Source{

public:

    SmothRandomSource(double startValue,
                        double minValue,
                        double maxValue, 
                        double delta);
    
    double readValue() override;

private:

    double current_;
    double delta_;
    double min_;
    double max_;
    std::mt19937 gen_;
    std::uniform_real_distribution<double> dist_;

};
