#include <iostream>
#include <string>

#include "welcome/greet.h"
#include "scripts/arrays/reduce/sum_all.hpp"

using namespace std;


const string RED = "\e[0;31m";

int main(){
    greet();

    int a[] = {5, 5, 5};
    cout << "Resultado da soma: " << sum_all(a);

    cin.ignore();
    return 0;
}