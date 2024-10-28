#ifndef UTILS_HAS_NUMBERS_HPP
    #define UTILS_HAS_NUMBERS_HPP

    #include <string>

    using namespace std;

    bool has_numbers(string text){
        for(size_t i = 0; i < text.length(); i++){
            if(text[i] > 47 && text[i] < 58) return true;
        }

        return false;
    }

#endif