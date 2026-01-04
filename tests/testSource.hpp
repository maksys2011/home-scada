#pragma once
#include "Source.hpp"
#include <vector>

class testSource : public Source
{
public:
    explicit testSource(std::vector<double>& val);
    double readValue()override;
    std::vector<double>getValues();
private:
    std::vector<double> values_;
    size_t index_ = 0;
};