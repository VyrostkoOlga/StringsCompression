//
//  Bisection.hpp
//  StringsCompression
//
//  Created by Olga Vyrostko on 07.09.17.
//  Copyright © 2017 OlgaVyrostko. All rights reserved.
//

#ifndef Bisection_hpp
#define Bisection_hpp

#include <stdio.h>
#include <string>
#include "Grammar.hpp"

class Bisection {
public:
    static Grammar* createGrammar(std::string* input);
private:
    static int64_t addRuleToGrammar(std::string* input, Grammar* grammar);
};

#endif /* Bisection_hpp */
