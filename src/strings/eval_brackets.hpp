#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

bool eval_brackets(string s) {
    const map<char, signed short int> BRACKETS_TYPES = {
        {'(', 1},
        {')', -1},
        {'[', 2},
        {']', -2},
        {'{', 3},
        {'}', -3}
    };

    signed short int bracket_count = 0;
    signed short int current_bracket = 0;
    vector<char> occs = {};

    for(size_t i = 0; i < s.length(); i++){
        bool its_parentheses = s[i] == '(' || s[i] == ')';
        bool its_bracket = s[i] == '[' || s[i] == ']';
        bool its_brace = s[i] == '{' || s[i] == '}';

        if(its_parentheses
        || its_bracket
        || its_brace){
            signed short int bracket_value = BRACKETS_TYPES.at(s[i]);
            occs.push_back(s[i]);

            if(bracket_value > 0) current_bracket = bracket_value;
            if(bracket_value < 0){
                try {
                    bracket_value += BRACKETS_TYPES.at(occs.at(occs.size() - 2));
                }catch(out_of_range e){
                    return false;
                }

                if(bracket_value != 0) return false;

                occs.pop_back();
                occs.pop_back();
            }

            bracket_count += (BRACKETS_TYPES.at(s[i]));
        }
    }

    if(bracket_count != 0) return false;

    return true;
}