#ifndef FACTORIAL_HPP
    #define FACTORIAL_HPP

    using namespace std;

    long long int factorial(int x){
        long long int acc = 1;
        do {
            acc *= x;
        }while(--x > 0); // <- Dica muito boa para while-loops semelhantes a for-loops.

        return acc;
    }
#endif