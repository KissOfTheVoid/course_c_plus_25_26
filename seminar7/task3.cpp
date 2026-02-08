/*
    Works with string library
    Takes an integer as input and displays its digits in reverse order using pointers and loops and checkes whether this number is a palindrome
*/

#include <iostream>
#include <string>

int main() {
    std::string s, new_s = "";
    std::cin >> s;
    std::cout << "Original: " << s << ", Reversed: ";
    int l = s.length();
    bool f = true;
    for (int i = 0; i < l; ++i) {
        if (s[i] != s[l-i-1]) f = false;
        new_s += s[l-i-1];
    }
    std::cout << new_s << " - ";
    if (f) std::cout << "Palindrome!";
    else std::cout << "Not a palindrome!";
    /*
    the output depends on the input data, assume it's as following
    ---input---
    12345
    --output---
    Original: 12345, Reversed: 54321 - Not a palindrome!
    ---input---
    12321
    --output---
    Original: 12321, Reversed: 12321 - Palindrome!
    */
    return 0;
}