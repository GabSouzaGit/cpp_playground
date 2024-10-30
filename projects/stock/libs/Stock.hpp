#ifndef PROJECT_STOCK_HPP
    #define PROJECT_STOCK_HPP

    #include <iostream>
    #include <map>
    #include <string>

    #include "Product.hpp"

    using namespace std;

    class StockError {
        private:
            const vector<string> ERRORS = {
                "Definição de limite de estocagem ultrapassa limite padrão.",
                "Propriedade do estoque com caracteres inválidos (unicode, especiais, etc.)",
                "Nome de identificação do estoque excede o numero máximo de caracteres.",
                "Texto descritivo sobre o estoque excede o numero máximo de caracteres."
            };

            string message;

        public:
            StockError(int error){
                this->message = this->ERRORS[error];
            }

            string reason(){
                return this->message;
            }
    };

    class Stock {
        private:
            const int MAXIMUM_STOCK_NAME_LENGTH = 3;
            const int MAXIMUM_DESCRIPTION_LENGTH = 500;
            const long long int MAXIMUM_STOCK_LIMIT = 1000000000;

            int stock_limit;

            string name;
            string description;
            map<string, Product*> stock_core = {};

        public:
            Stock(string name, string description, int stock_limit){
                if(stock_limit > this->MAXIMUM_STOCK_LIMIT) throw StockError(0);
                if(!string_to_upper(name)) throw StockError(1);
                if(name.length() > MAXIMUM_STOCK_NAME_LENGTH) throw StockError(2);
                if(description.length() > this->MAXIMUM_DESCRIPTION_LENGTH) throw StockError(3);

                this->name = name;
                this->stock_limit = stock_limit;
                this->description = description;
            }
    };

#endif