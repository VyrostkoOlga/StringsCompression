//
//  main.cpp
//  StringsCompression
//
//  Created by Olga Vyrostko on 07.09.17.
//  Copyright © 2017 OlgaVyrostko. All rights reserved.
//

#include <iostream>
#include <string>
#include <random>
#include "Bisection.hpp"

int test(std::string input);

int main(int argc, const char * argv[]) {
    char alph[4] = {'a', 'b', 'c', 'd'};
    
    std::string inp = "ab";
    for (size_t count = 2; count < 32565; ++count) {
        test(inp);
        inp.append(1, alph[random() % 4]);
    }
    return 0;
}

int test(std::string input) {
    Bisection* bs = new Bisection();
    Grammar* grammar = bs->createGrammar(&input);
    std::cout<<input.size()<<' ';
    std::cout<<(grammar->product()->compare(input) == 0)<<' ';
    std::cout<<grammar->rules->size()<<"\n";
    return 0;
}
