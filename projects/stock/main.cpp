#include <iostream>
#include <string>
#include <memory>

#include "libs/StockInterface.hpp"

using namespace std;

int main(){
    StockInterface::System sys = StockInterface::System();
    
    sys.boot();

    cin.ignore();
    return 0;
}