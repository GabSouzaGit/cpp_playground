#ifndef STRING_TO_UPPER_HPP 
    #define STRING_TO_UPPER_HPP

    #include <string>
    #include <cctype>
    #include "is_simple_letter.hpp"

    using namespace std;

    bool string_to_upper(string& str){
        for(size_t i = 0; i < str.length(); i++){
            if(!is_simple_letter(str[i])) return false;
            str[i] = toupper(str[i]);
        }

        return true;
    }

#endif