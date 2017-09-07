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
    this->axiom = -1;
    this->alph = new vector<char>();
    this->rules = new vector<Rule*>();
}

Grammar::~Grammar() {
    delete this->alph;
    delete this->rules;
}

char Grammar::symbolForMark(int64_t mark) {
    return this->alph->at(-mark - 1);
}

string* Grammar::product() {
    if (!this->rules->size()) {
        return new string();
    }
    
    vector<int64_t>* stack = new vector<int64_t>();
    stack->push_back(this->axiom);
    
    string* result = new string();
    int64_t currentSymbol;
    while (stack->size()) {
        currentSymbol = stack->back();
        stack->pop_back();
        if (currentSymbol < 0) {
            // has reached the terminal
            result->append(1, this->symbolForMark(currentSymbol));
            continue;
        }
        // nonterminal, need to product, from left to right
        Rule* currentRule = this->rules->at(currentSymbol);
        stack->push_back(currentRule->product[1]);
        stack->push_back(currentRule->product[0]);
    }
    delete stack;
    return result;
}

int64_t Grammar::addRule(int64_t lhs, int64_t rhs) {
    int64_t existedRule = this->findRule(lhs, rhs);
    if (existedRule >= 0) {
        return existedRule;
    }
    this->rules->push_back(new Rule(lhs, rhs));
    return this->rules->size() - 1;
}

int64_t Grammar::addSymbol(char symbol) {
    int64_t existedSymbol = this->findSymbol(symbol);
    if (existedSymbol < 0) {
        return existedSymbol;
    }
    this->alph->push_back(symbol);
    return -(this->alph->size());
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

int64_t Grammar::findSymbol(char symbol) {
    for (size_t symbolIdx = 0; symbolIdx < this->alph->size(); ++symbolIdx) {
        if (this->alph->at(symbolIdx) == symbol) {
            return -symbolIdx - 1;
        }
    }
    return 1;
}

