#ifndef PROJECT_STOCK_INTERFACE_HPP
    #define PROJECT_STOCK_INTERFACE_HPP

    #include <vector>
    #include <iostream>

    #include "Product.hpp"
    #include "Stock.hpp"
    #include "User.hpp"

    namespace StockInterface {

        using SessionProcedure = void(*)();

        class System {
            private:
                // PROCEDIMENTOS DE SESSÃO 
                SessionProcedure exit = []() -> void {

                };

                SessionProcedure visualize_stocks = []() -> void {

                };

                SessionProcedure visualize_profile = []() -> void {

                };

                /* * */

                const vector<SessionProcedure> SESSION_PROCEDURES = {
                    this->exit,
                    this->visualize_stocks,
                    this->visualize_profile
                };

                /* Prints */
                // Sobrecarga: string comum
                void print(string message){
                    cout << message << endl;
                }

                // Sobrecarga: multiplicação de caractere
                void print(char c, int x){
                    for(int i = 0; i < x; i++){
                        cout << c;
                    }

                    cout << endl;
                }

                void concat_print(vector<string> snippets){
                    for(size_t i = 0; i < snippets.size(); i++){
                        cout << snippets[i];
                    }

                    cout << endl;
                }

                void multiline_print(vector<string> lines){
                    for(size_t i = 0; i < lines.size(); i++){
                        cout << lines[i] << endl;
                    }
                }
                
                void input(string message, unique_ptr<string> &local_ptr){
                    string* temp_cin_value = new string;
                    this->print(message);

                    getline(cin, *temp_cin_value);
                    local_ptr = make_unique<string>(*temp_cin_value);

                    cout << endl;
                }

                void multiline_input(vector<string> lines, unique_ptr<string> &local_ptr){
                    string* temp_cin_value = new string;
                    this->multiline_print(lines);

                    getline(cin, *temp_cin_value);
                    local_ptr = make_unique<string>(*temp_cin_value);

                    cout << endl;
                }

                User* user_register(){
                    User* u = new User();
                    bool confirm_login = false;
                    while(!confirm_login){
                        unique_ptr<string> username, company_name;
                        this->input("Insira o seu nome de usuário: ", username);
                        this->input("Insira o nome da sua empresa: ", company_name);

                        try {
                            *u = User(username->data(), company_name->data());
                        }catch(UserError u_excpt){
                            this->print(u_excpt.reason());
                            continue;
                        }

                        this->print("Seu nome de registro: " + u->get_username());
                        this->print("Nome da sua empresa: " + u->get_company());

                        unique_ptr<string> confirmation;

                        while(true){
                            input("Seus dados aparecerão assim no sistema. Tem certeza que deseja prosseguir? (s/n): ", confirmation);

                            if(static_cast<string>(confirmation->data()).length() > 1){
                                print("Digite apenas 's' (sim) ou 'n' (não).");
                                continue;
                            }
                            if(*(confirmation->data()) == 's'){
                                confirm_login = true;
                                break;
                            }
                            if(*(confirmation->data()) == 'n'){
                                break;
                            }
                            else{
                                print("Digite apenas 's' (sim) ou 'n' (não).");
                            }
                        }

                    }

                    return u;
                }

                void start_session(User* user){
                    bool running = true;

                    concat_print({"SEJA BEM VINDO, ", user->get_username(), "!"});
                    print('-', 20);

                    while(running){
                        unique_ptr<string> opt;

                        try {
                            multiline_input({
                                "1 - Acessar estoques disponiveis",
                                "2 - Visualizar perfil",
                                "",
                                "0 - Sair"
                            }, opt);

                            this->SESSION_PROCEDURES[stoi(opt->data())]();
                        }catch(out_of_range e){
                            this->print("Digite apenas um dos valores disponiveis para prosseguir.");
                        }
                    }
                }          
            
            public:
                System(){}
                void boot(){
                    User* user = this->user_register();
                    this->start_session(user);
                }
        };
    };

#endif