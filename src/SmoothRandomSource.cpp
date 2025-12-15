#include "SmoothRandomSource.hpp"

SmothRandomSource::SmothRandomSource(double startValue,
                                        double deltaValue, 
                                        double minValue, 
                                        double maxValue)
        :   current_(startValue),   
            delta_(deltaValue),
            min_(minValue),
            max_(maxValue),
            gen_(std::random_device{}()),
            dist_(-deltaValue, deltaValue) 
{}

double SmothRandomSource::readValue()
{
    double delta = dist_(gen_);
    current_ += delta;
    if(current_ < min_) current_ = min_;
    if(current_ > max_) current_ = max_;

    return current_;
    
}
