#ifndef LINKED_LIST_HPP
    #define LINKED_LIST_HPP

    #include <iostream>

    using namespace std;

    template <typename T> class Node {
        public:
            T value;
            Node* next;

            Node(){}
            Node(T value){
                this->value = value;
                this->next = nullptr;
            }

            Node(T value, Node* next){
                this->value = value;
                this->next = next;
            }
    };

    template<typename T> class SingleLinkedList {
        private:
            int size = 0;

            Node<T>* head = nullptr;
            Node<T>* tail = nullptr;

            // Acrescenta mais uma unidade de tamanho à lista encadeada.
            void increment_size(){
                this->size++;
            }

            // Decresce menos uma unidade de tamanho à lista encadeada.
            void decrement_size(){
                this->size--;
            }

        public:
            LinkedList(){}
            LinkedList(T value){
                this->head = new Node<T>(value);
            }

            // Insere um novo valor no inicio da lista.
            void insert_at_begin(T value){
                this->increment_size();

                if(this->head  == nullptr){
                    this->head = new Node<T>(value, nullptr);
                    return;
                }

                if(this->tail == nullptr){
                    this->tail = new Node<T>(value, this->head);
                    return;
                }

                this->tail = new Node<T>(value, this->tail);
            }

            // Insere um novo valor no fim da lista.
            void insert_at_end(T value){
                this->increment_size();

                if(this->head == nullptr){
                    this->head = new Node<T>(value);
                    return;
                }

                Node<T>* current = this->tail;
                while(true){
                        if(current->next == nullptr){
                            current->next = new Node<T>(value, nullptr);
                            this->head = current;

                            return;
                        }

                        current = current->next;
                }
            }

            // Remove o valor localizado no inicio da lista.
            void remove_at_begin(){
                this->tail = this->tail->next;
                this->decrement_size();
            }

            // Remove o valor localizado no fim da lista.
            void remove_at_end(){
                Node<T>* current = this->tail;

                while(true){
                    if(current->next->next == nullptr){
                        this->head = current;

                        delete this->head->next;
                        this->head->next = nullptr;

                        this->decrement_size();
                        return;
                    }

                    current = current->next;
                }
            }

            // Retorna o primeiro elemento da lista.
            Node<T>* get_tail(){
                return this->tail;
            }

            // Retorna o ultimo elemento da lista.
            Node<T>* get_head(){
                return this->head;
            }

            // Retorna o tamanho atual da lista.
            int length(){
                return this->size;
            }

            // Exibe na tela do console a lista encadeada em forma de texto.
            void display(){
                cout << "[ ";

                Node<T>* current = this->tail;
                while(true){
                    if(current->next == nullptr){
                        cout << current->value << " => null ]" << endl;
                        return;
                    }

                    cout << current->value << " => ";
                    current = current->next;
                }
            }
    };

#endif