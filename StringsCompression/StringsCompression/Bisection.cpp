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
    
    vector<string*>* stack = new vector<string*>();
    stack->push_back(input);
    
    string* currentStr;
    while (stack->size()) {
        currentStr = stack->back();
        stack->pop_back();
        
        if (currentStr->size() == 2) {
            
        }
    }
}
