#include "testSource.hpp"

testSource::testSource(std::vector<double> &val)
{
    values_ = val;
}

double testSource::readValue()
{
    if(index_ < values_.size()){
        return values_[index_++];
    }else{ 
        return values_.back(); 
    }
}

std::vector<double> testSource::getValues()
{
    return values_;
}
