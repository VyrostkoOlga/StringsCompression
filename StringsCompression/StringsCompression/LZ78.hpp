//
//  LZ78.hpp
//  StringsCompression
//
//  Created by Olga Vyrostko on 02.09.17.
//  Copyright © 2017 OlgaVyrostko. All rights reserved.
//

#ifndef LZ78_hpp
#define LZ78_hpp

#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

typedef std::pair<size_t, char> factor;

class LZ78 {
public:
    std::vector<factor*>* factors;
    
    LZ78(std::string* inputStr);
    ~LZ78();
    
    std::string* extract;
    
private:
    std::string* extractFromFactor(size_t factorIdx);
    size_t findExistingFactor(std::string* str, size_t start, size_t count);
};

#endif /* LZ78_hpp */
