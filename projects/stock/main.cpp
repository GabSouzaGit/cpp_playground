#include <iostream>
#include <string>

#include "libs/User.hpp"

using namespace std;

void print(string message){
    cout << message << endl;
}

void input(string message, string &locate){
    cout << message;
    getline(cin, locate);
    cout << endl;
}

int main(){
    string username, company_name;
    User u;
    bool confirm_login = false;
    do {

        input("Insira o seu nome de usuário: ", username);
        input("Insira o nome da sua empresa: ", company_name);

        try {
            u = User(username, company_name);
        }catch(UserError u_excpt){
            print(u_excpt.reason());
            continue;
        }

        print("Seu nome de registro: " + u.get_username());
        print("Nome da sua empresa: " + u.get_company());
    }while(!confirm_login);

    cin.ignore();
    return 0;
}