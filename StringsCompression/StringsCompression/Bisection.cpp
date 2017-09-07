//
//  Bisection.cpp
//  StringsCompression
//
//  Created by Olga Vyrostko on 07.09.17.
//  Copyright © 2017 OlgaVyrostko. All rights reserved.
//

#include "Bisection.hpp"
#include <vector>

using namespace std;

Grammar* Bisection::createGrammar(std::string *input) {
    Grammar* result = new Grammar();
    return result;
}

int64_t Bisection::addRuleToGrammar(std::string* input, Grammar* grammar) {
    size_t length = input->size();
    switch (length) {
        case 1:
            <#statements#>
            break;
            
        default:
            break;
    }
}
