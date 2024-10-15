
# Seja bem vindo ao meu playground C++!

Este repositório tem a finalidade de compreender melhor a linguagem **C++** e suas aplicações.

Para isso, irei implementar diversas funções e objetos que realizarão diversas tarefas, seja desde um simples **reduce** à até um **backtracking**, e claro, a implementação de algoritmos vai ficando mais complexa a medida que compreendo melhor a linguagem (o que vai demorar um pouco pq to no básico kkk).

## 🔌 Instalação e Execução
Partindo do principio que você já tenha o `gcc` e o `g++` instalado, você pode pular esta parte do tutorial. Mas caso tenha duvidas de como instala-los, eu posso lhe ajudar!

---

### 🏠 Windows
No ambiente Windows você vai precisar instalar o **MinGW**. O MinGW é uma versão portada do conjunto de ferramentas do GNU para Windows. A partir dele, iremos conseguir instalar o compilador `g++` (compilador direcionado para o C++).

[*Clicando aqui*](https://sourceforge.net/projects/mingw/files/), você vai baixar o MinGW:

- Ao baixa-lo, abra o instalador dele e siga instalando o programa até a tela de recursos.
- Na tela de recursos, na coluna *package* (ou pacote), **procure pelos seguintes pacotes**:
    - *mingw32-base **bin***
    - *mingw32-gcc-g++ **bin***
    - *mingw32-gcc-g++ **dev***
- Após isso, clique em *Installation* e em *Apply Changes.*

Com os compiladores do C e do C++ já instalados, agora devemos adicionar o caminho do MinGW na variável de ambiente **PATH** do Windows, para que os compiladores sejam acessíveis pelo sistema de forma global. 

- No seu computador, vá até o disco local (C:).
- Procure por uma pasta chamada *MinGW.* 
- Entre nesta pasta, procure a pasta *bin* e copie o caminho até ela.

Agora, para inseri-la na variável de ambiente:

- No Windows, pesquise por **Editar variáveis de ambiente do sistema** e acesse.
- Nesta janela, clique num botão escrito **Variáveis de ambiente**.
- Na seção **Variáveis do sistema**, procure pela variável **Path**.
- Clique nela e depois no botão **Editar**.
- Clique em **Novo** e cole o caminho até a *bin* do MinGW.
- Por fim, clique em **Ok** e saia de todas as janelas.

Caso reste duvidas se a instalação foi feita com sucesso, abra o prompt de comando do Windows e digite `g++`. Se aparecer a seguinte mensagem:

`g++: fatal error: no input files`
`compilation terminated.`

Isso indica que o compilador foi instalado e já está funcionando 👍.

---

### 📦 Importação do repositório
Instale o cpp-playground no seu diretório desejado.

```bash
    git clone https://github.com/GabSouzaGit/cpp_playground
    cd cpp_playground
```

Dentro do repositório, há o arquivo `main.cpp`, onde ocorrem as importações e execuções dos módulos.

---

### 📋 Para usuários do VSCode

Caso não queira ter o trabalho de escrever todo o prompt toda vez que for compilar o código, eu deixei uma task do VSCode para te ajudar nisto.

Basicamente, esta task contém toda a estrutura do prompt para compilação já feita, contendo por padrão já o código da `main.cpp` e as mensagens de boas vindas. Tudo o que ela vai precisar de fora são apenas os headers e as implementações adicionais que você importou para o código principal.

A task está presente no diretório *.vscode*, em `tasks.json`:

```json
    {
        "version": "2.0.0",
        "tasks": [
            {
                "label": "🔄 Compilar arquivos do playground (C++)",
                "detail": "Compile todos os arquivos definidos na task.",
                "type": "shell",
                "command": "g++",
                "args": [
                    "-g",
                    // Arquivos compilados por padrão (não mexer, na boa ^_-)
                        "main.cpp",
                        "greet.hpp",

                    // Insira aqui os arquivos e cabeçalhos que serão carregados pelo arquivo main.cpp
                        // "scripts/caminho/example.cpp",
                        // "scripts/caminho/example.hpp",
                        
                    "-o",
                    "output/instance"
                ],
                "group": {
                    "kind": "build",
                    "isDefault": false
                },
                "problemMatcher": [
                    "$gcc"
                ]
            }
        ]
    }
```

Para executar a task, pressione `Ctrl+Shift+B`, e proximo da barra de pesquisa do VSCode, clique na opção escrita **🔄 Compilar arquivos do playground (C++)**.

Ao compilar o programa, ele gerará um arquivo chamado `instance.exe`, dentro da pasta *output*, contendo um executável do programa.  


    