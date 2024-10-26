#ifndef PAYBACK_HPP
    #define PAYBACK_HPP

    #include <vector>
    #include <map>
    #include "../../utils/to_money.hpp"
    
    using namespace std;

    char get_last_char(string str){
        return str.at(str.length() - 1);
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