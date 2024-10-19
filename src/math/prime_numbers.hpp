#ifndef PRIME_NUMBERS_HPP
    #define PRIME_NUMBERS_HPP

    #include <vector>

    using namespace std;

    vector<int> prime_numbers(int n){
        vector<int> numbers = {2, 3, 5, 7};

        if(n <= 0) return numbers;

        for(int x = 2; x <= n; x++){
            if(x % 2 == 0) continue; 
            if(x % 3 == 0) continue;
            if(x % 5 == 0) continue;
            if(x % 7 == 0) continue;

            numbers.push_back(x);
        }

        return numbers;
    }

#endif