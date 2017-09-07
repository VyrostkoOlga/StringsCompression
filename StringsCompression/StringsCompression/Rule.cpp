//
//  Rule.cpp
//  StringsCompression
//
//  Created by Olga Vyrostko on 07.09.17.
//  Copyright © 2017 OlgaVyrostko. All rights reserved.
//

#include "Rule.hpp"

bool Rule::operator==(const Rule &rhs) {
    return (*this).product[0] == rhs.product[0] && (*this).product[1] == rhs.product[1];
}
