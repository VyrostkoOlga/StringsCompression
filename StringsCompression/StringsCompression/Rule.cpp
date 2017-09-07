//
//  Rule.cpp
//  StringsCompression
//
//  Created by Olga Vyrostko on 07.09.17.
//  Copyright © 2017 OlgaVyrostko. All rights reserved.
//

#include "Rule.hpp"

Rule::Rule(int64_t lhs, int64_t rhs) {
    this->product[0] = lhs;
    this->product[0] = rhs;
}

bool Rule::operator==(const Rule &rhs) {
    return (*this).product[0] == rhs.product[0] && (*this).product[1] == rhs.product[1];
}
