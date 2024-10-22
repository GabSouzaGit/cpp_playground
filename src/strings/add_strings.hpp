#include <string>

using namespace std;

int ctoi(char c){
    return c - '0';
}

string add_strings(string num1, string num2) {
    string bigger = num1;
    string minor = num2;
                                                
    if(num1.length() != num2.length()){
        if(num1.length() < num2.length()){
            bigger = num2;
            minor = num1;
        }

        int left_zeros_number = bigger.length() - minor.length();
        string zeros = "";
        for(int x = 0; x < left_zeros_number; x++){
            zeros += "0";
        }

        minor = zeros + minor;
    }
    
    string sum = "";
    int current_rest = 0;
    
    for(int i = bigger.length() - 1; i >= 0; i--){              
        int digit_from_bigger = ctoi(bigger[i]);
        int digit_from_minor = ctoi(minor[i]);
        
        int sum_between_digits = digit_from_bigger + digit_from_minor;
        
        if(current_rest != 0){
            sum_between_digits += current_rest;
            current_rest = 0;
        }

        if(i == 0){
            sum = to_string(sum_between_digits) + sum;
            break;
        }
        
        if(sum_between_digits > 9 && (bigger.length() + minor.length()) > 2){
            string rest = to_string(sum_between_digits);
            current_rest = ctoi(rest[0]);
            sum = rest[1] + sum;
        
            continue;
        }

        sum = to_string(sum_between_digits) + sum;
    } 

    return sum;
}