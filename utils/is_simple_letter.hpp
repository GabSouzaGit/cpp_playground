#ifndef IS_SIMPLE_LETTER_HPP 
    #define IS_SIMPLE_LETTER_HPP

    #include <iostream>
    #include <string>
    #include <cctype>

    using namespace std;

    bool is_simple_letter(char32_t c){
        const bool IN_UPPER_LETTERS_GROUP = c > 64 && c < 91;
        const bool IN_LOWER_LETTERS_GROUP = c > 96 && c < 123;
        const bool IS_SPACE = c == 32;

        if(IN_UPPER_LETTERS_GROUP || IN_LOWER_LETTERS_GROUP || IS_SPACE) return true;

        return false;
    }

#endif