#include "sum_all.hpp"

int sum_all(int array[]){
    const int ARRAY_SIZE = sizeof(array) / sizeof(int);
    int acc = 0;

    for(int i = 0; i < ARRAY_SIZE; i++){
        acc += array[i];
    }

    return acc;
}