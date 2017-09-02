//
//  main.cpp
//  1
//
//  Created by Olga Vyrostko on 02.09.17.
//  Copyright © 2017 OlgaVyrostko. All rights reserved.
//

#include <iostream>
#include "LZ78.hpp"

int test(std::string input);

int main(int argc, const char * argv[]) {
    test("abab");
    return 0;
}

int test(std::string input) {
    LZ78 factorization = LZ78(&input);
    return 0;
}
