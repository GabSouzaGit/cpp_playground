#ifndef PROJECT_USER_HPP
    #define PROJECT_USER_HPP

    #include <iostream>
    #include <vector>
    #include <map>

    #include "../../../utils/string_to_upper.hpp"
    #include "../../../utils/has_numbers.hpp"

    #include "Stock.hpp"

    using namespace std;

    class UserError {
        private:
            const vector<string> ERRORS = {
                "Propriedade do usuário com caracteres inválidos (unicode, especiais, etc.)",
                "O usuário precisa ter todos os campos preenchidos."
            };

            string message;

        public:
            UserError(int error){
                this->message = this->ERRORS[error];
            }

            string reason(){
                return this->message;
            }
    };

    class User {
        private:
            string company_name = "UNDEFINED_COMPANY";
            string username = "UNDEFINED_USERNAME";
            map<string, Stock*> stores;

        public:
            User(){}
            User(string username, string company_name){
                if(!string_to_upper(company_name)) throw UserError(0);
                if(has_numbers(username) || !string_to_upper(username)) throw UserError(0);
                if(company_name == "" || username == "") throw UserError(1);

                this->company_name = company_name;
                this->username = username;
            }

            string get_username(){
                return this->username;
            }

            string get_company(){
                return this->company_name;
            }
    };

#endif