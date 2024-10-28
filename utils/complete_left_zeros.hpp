#ifndef UTILS_COMPLETE_LEFT_ZEROS_HPP 
    #define UTILS_COMPLETE_LEFT_ZEROS_HPP

    #include <string>
    #include <cmath>

    using namespace std;

    string complete_left_zeros(int x, int total_length){
        x = abs(x);
        total_length = abs(total_length);

        string formatted = "";
        string x_as_str = to_string(x);
        
        if(x_as_str.length() >= total_length) return x_as_str;

        for(int k = 0; k < total_length - x_as_str.length(); k++){
            formatted += '0';
        }

        return formatted + x_as_str;
    }

#endif