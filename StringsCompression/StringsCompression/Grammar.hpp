//
//  Grammar.hpp
//  StringsCompression
//
//  Created by Olga Vyrostko on 07.09.17.
//  Copyright © 2017 OlgaVyrostko. All rights reserved.
//

#ifndef Grammar_hpp
#define Grammar_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include "Rule.hpp"

class Grammar {
public:
    uint64_t axiom;
    std::vector<char>* alph;
    std::vector<Rule*>* rules;
    
    Grammar();
    ~Grammar();
    
    // products the string using grammar's rules
    std::string* product();
    // returns the symbol of the alphabet
    // connected with the mark
    char symbolForMark(int64_t mark);
    
    // adds a new rule for left and right parts of product to a grammar
    // and returns the symbol for it or just returns the symbol for
    // existing rule if it's been already added to a grammar
    int64_t addRule(int64_t lhs, int64_t rhs);
    // adds a new symbol to the alphabet of a grammar and
    // returns the mark for it or just returns the mark if
    // symbol has already been added to the alphabet
    int64_t addSymbol(char symbol);
    
    // finds and returns index of rule for left and right parts of product
    // or -1 if rule for the product does not exist
    int64_t findRule(int64_t lhs, int64_t rhs);
    // finds and returns mark of symbol in the alphabet
    // or +1 if symbol has not been added to alphabet
    int64_t findSymbol(char symbol);
};

#endif /* Grammar_hpp */
