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
    std::vector<char>* alph;
    std::vector<Rule*>* rules;
    std::string* product();
    
    Grammar();
    ~Grammar();
    
    int64_t findRule(int64_t lhs, int64_t rhs);
};

#endif /* Grammar_hpp */
