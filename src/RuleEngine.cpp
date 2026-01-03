#include "RuleEngine.hpp"
#include "Rule.hpp"

void RuleEngine::addRule(Rule *rule)
{
    rules_.push_back(rule);
}

void RuleEngine::evaluateRules()
{
    for (auto& rule : rules_)
    {
        rule->evaluate();
    }
}
