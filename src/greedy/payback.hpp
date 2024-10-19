#ifndef PAYBACK_HPP
    #define PAYBACK_HPP

    #include <iomanip>
    #include <vector>
    #include <string>
    #include <sstream>
    #include <map>
    
    using namespace std;

    char get_last_char(string str){
        return str.at(str.length() - 1);
    }

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

    map<string, int> payback(float value, float payment){
        map<string, int> payback_coins = {
            {"0.05", 0},            
            {"0.10", 0},
            {"0.25", 0},
            {"0.50", 0},
            {"1.00", 0}
        };

        const vector<float> COINS_FLOAT_VALUES = {1.00, 0.50, 0.25, 0.10, 0.05};

        string value_str = to_money(value);
        string payment_str = to_money(payment);

        if((get_last_char(value_str) != '0' && get_last_char(value_str) != '5')
        || (get_last_char(payment_str) != '0' && get_last_char(payment_str) != '5')){
            
            return payback_coins;
        }

        value = stof(value_str);
        payment = stof(payment_str);

        if(value >= payment){
            return payback_coins;
        }

        float rest = payment - value;

        while(rest > 0){
            for(int i = 0; i < COINS_FLOAT_VALUES.size(); i++){
                float coin_value = COINS_FLOAT_VALUES.at(i);
                
                if(rest - coin_value < 0) continue;

                ostringstream coin_key_stream;
                coin_key_stream << fixed << setprecision(2) << coin_value; 

                payback_coins.at(coin_key_stream.str())++;

                rest -= coin_value;
                break;
            }
        }

        return payback_coins;
    }

#endif  