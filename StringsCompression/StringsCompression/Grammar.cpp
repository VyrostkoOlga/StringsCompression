//
//  Grammar.cpp
//  StringsCompression
//
//  Created by Olga Vyrostko on 07.09.17.
//  Copyright © 2017 OlgaVyrostko. All rights reserved.
//

#include "Grammar.hpp"

using namespace std;

Grammar::Grammar() {
    this->alph = new vector<char>();
    this->rules = new vector<Rule*>();
}

Grammar::~Grammar() {
    delete this->alph;
    delete this->rules;
}

string* Grammar::product() {
    if (!this->rules->size()) {
        return new string();
    }
    
    vector<int64_t>* stack = new vector<int64_t>();
    stack->push_back(0);
    
    string* result = new string();
    int64_t currentSymbol;
    while (stack->size()) {
        currentSymbol = stack->back();
        stack->pop_back();
        if (currentSymbol < 0) {
            result->append(&this->alph->at(currentSymbol));
            continue;
        }
        Rule* currentRule = this->rules->at(currentSymbol);
        stack->push_back(currentRule->product[0]);
        stack->push_back(currentRule->product[1]);
    }
    delete stack;
    return result;
}

int64_t Grammar::findRule(int64_t lhs, int64_t rhs) {
    Rule* rule;
    for (size_t ruleIdx = 0; ruleIdx < this->rules->size(); ++ruleIdx) {
        rule = this->rules->at(ruleIdx);
        if ((rule->product[0] == lhs) && (rule->product[1] == rhs)) {
            return ruleIdx;
        }
    }
    return -1;
}

