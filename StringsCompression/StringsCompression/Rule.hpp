//
//  Rule.hpp
//  StringsCompression
//
//  Created by Olga Vyrostko on 07.09.17.
//  Copyright © 2017 OlgaVyrostko. All rights reserved.
//

#ifndef Rule_hpp
#define Rule_hpp

#include <stdio.h>
#include <string>

class Rule {
public:
    int64_t product[2];
    
    bool operator ==(const Rule &rhs);
};

#endif /* Rule_hpp */
