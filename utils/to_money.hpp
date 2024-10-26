#ifndef UTILS_TO_MONEY_HPP
    #define UTILS_TO_MONEY_HPP
    
    #include <string>
    #include <iomanip>
    #include <sstream>

    using namespace std;

    string to_money(float f){
        string str = to_string(f);
        size_t pos_before_zero = str.find_last_not_of("0");

        if(pos_before_zero == string::npos) return "0";

        string brute_value = str.substr(0, pos_before_zero + 1);
        if(brute_value[pos_before_zero] == '.') return brute_value + "00";
        
        ostringstream money;
        size_t point_pos = brute_value.find(".");

        if(brute_value.size() - point_pos != 3){
            money << fixed << setprecision(2) << stof(brute_value);

            return money.str();
        }

        return brute_value;
    }

#endif