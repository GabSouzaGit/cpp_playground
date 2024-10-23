#ifndef LINEAR_SEARCH_HPP
    #define LINEAR_SEARCH_HPP

    #include <vector>

    using namespace std;

    template <typename T>
    bool linear_search(vector<T> array, T value){
        for(int i = 0; i < array.size(); i++){
            if(array[i] == value) return true;
        }

        return false;   
    }
    
#endif