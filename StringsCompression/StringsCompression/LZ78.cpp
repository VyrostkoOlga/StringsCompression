//
//  LZ78.cpp
//  StringsCompression
//
//  Created by Olga Vyrostko on 02.09.17.
//  Copyright © 2017 OlgaVyrostko. All rights reserved.
//

#include "LZ78.hpp"
#include <iostream>

using namespace std;

LZ78::LZ78(std::string* inputString) {
    this->factors = new vector<factor*>;
    
    size_t index = 0;
    while (index < inputString->size()) {
        size_t count = 0;
        size_t factorIdx = 0;
        while (index + count < inputString->size()) {
            size_t currentFactorIdx = this->findExistingFactor(inputString, index, ++count);
            if (!currentFactorIdx) {
                break;
            }
            factorIdx = currentFactorIdx;
        }
        
        factor* newFactor = new factor();
        newFactor->first = factorIdx;
        newFactor->second = inputString->at(index + count - 1);
        this->factors->push_back(newFactor);
        index += count;
    }
    
    for (vector<factor*>::iterator it = this->factors->begin(); it != this->factors->end(); ++it) {
        cout<<(*it)->first<<" "<<(*it)->second<<"\n";
    }
}

LZ78::~LZ78() {
    delete this->factors;
}

#pragma mark - private 

string* LZ78:: extractFromFactor(size_t factorIdx) {
    factor* factor = this->factors->at(factorIdx);
    if (!factor->first) {
        return new string(&factor->second);
    }
    return new string(this->extractFromFactor(factor->first - 1)->append(1, factor->second));
}

size_t LZ78::findExistingFactor(string* str, size_t start, size_t count) {
    // scans factoization from left to right and find factor extracts substring
    // of str from start, count characters
    
    for (size_t index = 0; index < this->factors->size(); ++index) {
        string substr = str->substr(start, count);
        if (!this->extractFromFactor(index)->compare(substr)) {
        //if (this->extractFromFactor(index)->compare(start, count, *str) == 0) {
            return index + 1;
        }
    }
    return 0;
}
