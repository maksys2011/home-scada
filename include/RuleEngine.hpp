#pragma once
#include <vector>

class Rule;

class RuleEngine
{
public:
    
    void addRule(Rule* rule);
    void evaluateRules();

private:
    
    std::vector<Rule*> rules_;

};