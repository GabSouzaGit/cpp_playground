#include <iostream>

#include "libs/Product.hpp";

using namespace std;

int main(){
    try {
        Product p = Product(13, "camiseta slpk preta", 5, 50, 0.2, "SLPK LTDA");
        p.get_description();
    }catch(ProductError pe){
        cout << "Erro: " << pe.reason() << endl;
    }

    cin.ignore();
    return 0;
}