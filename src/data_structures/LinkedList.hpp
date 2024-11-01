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

    template<typename T> class LinkedList {
        private:
            Node<T>* head = nullptr;
            Node<T>* tail = nullptr;

        public:
            LinkedList(){}
            LinkedList(T value){
                this->head = new Node<T>(value);
            }

            void insert_at_begin(T value){
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

            void insert_at_end(T value){
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

            Node<T>* get_tail(){
                return this->tail;
            }

            Node<T>* get_head(){
                return this->head;
            }

            void display(){
                cout << "[ ";

                Node<T>* current = this->tail;
                while(true){
                    if(current->next == nullptr){
                        cout << current->value << " => null ]";
                        return;
                    }

                    cout << current->value << " => ";
                    current = current->next;
                }
            }
    };

#endif