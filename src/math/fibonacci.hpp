#ifndef FIBONACCI_HPP
    #define FIBONACCI_HPP

    #include <vector>

    using namespace std;

    vector<int> fibonacci(int qtd){
        vector<int> fib = {1, 1};
        for(int x = 1; x < qtd - 1; x++){
            fib.push_back(fib[x - 1] + fib[x]);
        }

        return fib;
    }

#endif