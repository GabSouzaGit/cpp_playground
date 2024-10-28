
# Seja bem vindo ao meu playground C++!

Este repositório tem a finalidade de compreender melhor a linguagem **C++** e suas aplicações.

Para isso, irei implementar diversas funções, objetos e projetos que realizarão diversas tarefas, e a medida em que eu compreendo melhor a linguagem, mais complexas vão se tornando as implementações dos algoritmos.

---

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
`compilation terminated`

Isso indica que o compilador foi instalado e já está funcionando 👍.

## 📍 Rodando localmente
---
### 📦 Importação do repositório
Instale o cpp-playground no seu diretório desejado.

```bash
    git clone https://github.com/GabSouzaGit/cpp_playground
    cd cpp_playground
```

Dentro do repositório, há os módulos e os projetos. Módulos são funções e classes que são importadas para a `main.cpp`, enquanto os projetos são códigos maiores e mais robustos, que são separados do arquivo principal.

---

### 📋 Para usuários do VSCode

Caso não queira ter o trabalho de escrever todo o prompt toda vez que for compilar um código, eu deixei duas tasks do VSCode para te ajudar nisto.

Em resumo, o projeto contém tasks com toda a estrutura do prompt para compilação já feita, seja a compilação para projetos ou para módulos. A task por padrão já contém o código da `main.cpp`, as mensagens de boas vindas e os `utils` usados em todo o repositório. 

Tudo o que você vai precisar definir são apenas os módulos que você importou para o código principal ou o projeto que deseja executar.

**As tasks estão presentes no diretório *.vscode*, em `tasks.json`:**

---

Para executar qualquer task, pressione **`Ctrl+Shift+B`**, e proximo da barra de pesquisa do VSCode, irão aparecer duas opções:

**🔄 Compilar módulos C++ (playground)**: indicado caso queira usar módulos dentro da `main.cpp`. Apenas aponte o caminho dos módulos usados no arquivo principal. Ao compilar o programa, ele gerará um arquivo chamado `instance.exe`.  

**🗃️ Carregar projeto C++ (playground)**: indicado caso queira executar um projeto separadamente. Apenas aponte o caminho para o código-fonte do projeto e seus cabeçalhos padrões. Ao compilar o programa, ele gerará um arquivo chamado `project.exe`.  

**Em ambos os casos, o executável será criado dentro da pasta `/output`**

---

```json
    {
        "version": "2.0.0",
        "tasks": [
            {
                "label": "🔄 Compilar módulos C++ (playground)",
                "detail": "Compile todos os módulos importados para a main.cpp.",
                "type": "shell",
                "command": "g++",
                "args": [
                    "-g",
                    // Arquivos compilados por padrão (não mexer, na boa ^_-)
                        "main.cpp",
                        "greet.hpp",
                        "-I utils",

                    // Insira aqui os cabeçalhos que serão carregados pelo arquivo main.cpp
                        // "src/caminho/example.hpp",
                        
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
            },
            {
                "label": "🗃️ Carregar projeto C++ (playground)",
                "detail": "Carregar projeto especifico do repositório.",
                "type": "shell",
                "command": "g++",
                "args": [
                    "-g",
                    "-I utils",

                    // Insira aqui o codigo-fonte do projeto e seus cabeçalhos.
                        // "-I projects/example/libs",
                        // "projects/example/main.cpp",

                    "-o",
                    "output/project"
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