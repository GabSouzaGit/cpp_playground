#ifndef PROJECT_COMPANY_HPP
    #define PROJECT_COMPANY_HPP

    #include <iostream>
    #include <vector>
    #include <map>

    #include "../../../utils/string_to_upper.hpp"
    #include "../../../utils/has_numbers.hpp"

    #include "Stock.hpp"

    using namespace std;

    class CompanyError {
        private:
            const vector<string> ERRORS = {
                "Propriedade do usuário com caracteres inválidos (unicode, especiais, etc.)",
            };

            string message;

        public:
            CompanyError(int error){
                this->message = this->ERRORS[error];
            }

            string reason(){
                return this->message;
            }
    };

    class Company {
        private:
            string name;
            string owner;
            map<string, Stock> stores;

        public:
            Company(string name, string owner){
                if(!string_to_upper(name)) throw CompanyError(0);
                if(has_numbers(owner) || !string_to_upper(owner)) throw CompanyError(0);

                this->name = name;
                this->owner = owner;
            }
    };

#endif