/*
    Wors with string, vector libraries
    Demonstrates the diffenece between enum and enum class (see commented lines)
*/

#include <iostream>
#include <string>
#include <vector>

enum genre {
    LIGHT_ROCK,
    ROCK,
    ALTERNATIVE_ROCK,
    METAL,
    POP
};

enum class cgenre {
    LIGHT_ROCK,
    ROCK,
    ALTERNATIVE_ROCK,
    METAL,
    POP
};

int main() {
    genre mine = ALTERNATIVE_ROCK;
    // cgenre yours = ALTERNATIVE_ROCK; // a value of type "genre" cannot be used to initialize an entity of type "cgenre"
    cgenre sub_mine = cgenre::ALTERNATIVE_ROCK;
    cgenre sub_yours = cgenre::ALTERNATIVE_ROCK;

    if (mine == 2) std::cout << "mine alt";
    // if (sub_yours == 2) std::cout << "yours alt"; 
// ^^^^^^ no operator "==" matches these operands
    //if (sub_mine == 2) std::cout << "sub mine alt";
    // if (mine == sub_mine) std::cout << "mine equal sub mine";
    // if (mine == sub_yours) std::cout << "mine equal yours"; 
// ^^^^^^ no operator "==" matches these operands
    /*
    ---output---
    mine alt
    */
    return 0;
}