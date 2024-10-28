#ifndef PROJECT_STOCK_PRODUCT_HPP
    #define PROJECT_STOCK_PRODUCT_HPP

    #include <string>
    #include <vector>
    #include <cmath>

    #include "../../../utils/to_money.hpp"
    #include "../../../utils/string_to_upper.hpp"
    #include "../../../utils/complete_left_zeros.hpp"

    class ProductError {
        private:
            const vector<string> ERRORS = {
                "Código acima do numero de digitos permitido.",
                "Propriedade contendo caracteres unicode (UTF-8)",
            };

            string message;

        public:
            ProductError(int error){
                this->message = this->ERRORS[error];
            }

            string reason(){
                return this->message;
            }
    };

    class Product {
        private:
            const int MAXIMUM_CODE_DIGITS = 6;
            const int MAXIMUM_NAME_CHARS = 60;

            string idcode;
            string name;
            string origin;

            int mmq;

            float price_per_unit;
            float total_weight;

        public:
            Product(int idcode, string name, int mmq, float price_per_unit, float weight_per_unity, string origin){
                const bool OVERFLOW_IDCODE_DIGITS = to_string(idcode).length() > this->MAXIMUM_CODE_DIGITS;

                if(OVERFLOW_IDCODE_DIGITS) throw ProductError(0);

                this->idcode = complete_left_zeros(idcode, this->MAXIMUM_CODE_DIGITS);

                if(!string_to_upper(name)) throw ProductError(1);
                if(!string_to_upper(origin)) throw ProductError(1);

                this->origin = origin;
                this->name = name;
                this->mmq = mmq;
                this->price_per_unit = price_per_unit;
                this->total_weight = weight_per_unity * mmq;
            }

            void get_description(){
                cout << "DESCRIÇÃO DO PRODUTO" << endl;
                cout << "--------------------" << endl << endl;
                cout << "Nome: " << this->name << endl;
                cout << "Quantidade por conjunto: " << this->mmq << endl;
                cout << "Valor total: R$" << to_money(this->price_per_unit * mmq) << endl;
                cout << "Peso do conjunto (KG): " << this->total_weight << endl;
                cout << "Origem: " << this->origin << endl << endl;
                cout << "--------------------" << endl << endl;
                cout << "Código de identificação: " << this->idcode << endl;
            }
    };

#endif