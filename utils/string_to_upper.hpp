#ifndef STRING_TO_UPPER_HPP 
    #define STRING_TO_UPPER_HPP

    #include <string>
    #include <cctype>

    using namespace std;

    string string_to_upper(string str){
        for(size_t i = 0; i < str.length(); i++){
            str[i] = toupper(str[i]);
        }

        return str;
    }

#endif