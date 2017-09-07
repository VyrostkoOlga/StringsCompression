//
//  Bisection.cpp
//  StringsCompression
//
//  Created by Olga Vyrostko on 07.09.17.
//  Copyright © 2017 OlgaVyrostko. All rights reserved.
//

#include "Bisection.hpp"
#include <vector>
#include <math.h>

using namespace std;

Grammar* Bisection::createGrammar(std::string *input) {
    Grammar* result = new Grammar();
    result->axiom = addRuleToGrammar(input, 0, input->size(), result);
    return result;
}

int64_t Bisection::addRuleToGrammar(std::string* input, size_t start, size_t end, Grammar* grammar) {
    size_t length = end - start;
    switch (length) {
        case 1: {
            // just one symbol - need to add a new symbol to a grammar and return
            // its mark
            return grammar->addSymbol(input->at(start));
        }
        case 2: {
            // two symbols - to need to split any more, just add lhs and rhs
            // symbols to a grammar and then add the rule with mark for the first
            // symbol as lhs and mark for the second symbol as rhs
            int64_t lhs = grammar->addSymbol(input->at(start));
            int64_t rhs = grammar->addSymbol(input->at(start + 1));
            return grammar->addRule(lhs, rhs);
        }
        default:
            // need recursive calls to process long strings
            
            // TODO: think about it = maybe it could be done better
            uint64_t separator = 1 << uint64_t(floor(log2(length - 1)));
            int64_t lhs = addRuleToGrammar(input, start, start + separator, grammar);
            int64_t rhs = addRuleToGrammar(input, start + separator, end, grammar);
            return grammar->addRule(lhs, rhs);
    }
}
