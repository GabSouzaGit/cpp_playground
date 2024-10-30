#ifndef PROJECT_STOCK_INTERFACE_HPP
    #define PROJECT_STOCK_INTERFACE_HPP

    #include <vector>

    #include "Product.hpp"
    #include "Stock.hpp"
    #include "User.hpp"

    namespace StockInterface {
        class System {
            private:
                /* Prints */
                // Sobrecarga: string comum
                void print(string message){
                    cout << message << endl;
                }

                void concat_print(vector<string> snippets){
                    for(size_t i = 0; i < snippets.size(); i++){
                        cout << snippets[i];
                    }

                    cout << endl;
                }

                // Sobrecarga: multiplicação de caractere
                void print(char c, int x){
                    for(int i = 0; i < x; i++){
                        cout << c;
                    }

                    cout << endl;
                }

                void multiline_print(vector<string> lines){

                    
                    for(size_t i = 0; i < lines.size(); i++){
                        cout << lines[i] << endl;
                    }
                }
                
                /* Inputs inline */
                // Sobrecarga: atribuição de entrada de usuario em string.
                void input(string message, string &locate){
                    this->print(message);
                    getline(cin, locate);
                    cout << endl;
                }

                // Sobrecarga: atribuição de entrada de usuario para ponteiro dinâmico de string.
                void input(string message, unique_ptr<string> &local_ptr){
                    string* temp_cin_value = new string;
                    this->print(message);

                    getline(cin, *temp_cin_value);
                    local_ptr = make_unique<string>(*temp_cin_value);

                    cout << endl;
                }
            
                /* Inputs multiline */
                // Sobrecarga: atribuição de entrada de usuario em string.
                void multiline_input(vector<string> lines, string &locate){
                    multiline_print(lines);
                    getline(cin, locate);
                    cout << endl;
                }

                // Sobrecarga: atribuição de entrada de usuario para ponteiro dinâmico de string.
                void multiline_input(vector<string> lines, unique_ptr<string> &local_ptr){
                    string* temp_cin_value = new string;
                    this->multiline_print(lines);

                    getline(cin, *temp_cin_value);
                    local_ptr = make_unique<string>(*temp_cin_value);

                    cout << endl;
                }

                // Sobrecarga: atribuição de entrada de usuario para ponteiro dinâmico de inteiro.
                void multiline_input(vector<string> lines, unique_ptr<int> &local_ptr){
                    string* temp_cin_value = new string;
                    this->multiline_print(lines);

                    getline(cin, *temp_cin_value);
                    local_ptr = make_unique<int>(stoi(*temp_cin_value));

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
            
            public:
                System(){}
                void boot(){
                    User* user = this->user_register();
                }
        };
    };

#endif