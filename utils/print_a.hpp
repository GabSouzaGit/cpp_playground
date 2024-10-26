#ifndef UTILS_PRINT_ARRAY_HPP
    #define UTILS_PRINT_ARRAY_HPP
    
    #include <vector>
    #include <iostream>

    using namespace std;

    template<typename T>
    void print_a(vector<T> array){
        cout << "[ ";

        for(size_t i = 0; i < array.size(); i++){
            if(array.size() - i == 1){
                cout << array[i] << " ]";
                return;
            }

            cout << array[i] << ", ";
        }

        cout << endl;
    }

#endif