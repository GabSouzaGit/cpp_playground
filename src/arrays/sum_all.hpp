#ifndef SUM_ALL_HPP
    #define SUM_ALL_HPP

    #include <vector>
    
    using namespace std;

    int sum_all(vector<int> array){
        int acc = 0;

        for(int i = 0; i < array.size(); i++){
            acc += array[i];
        }

        return acc;
    }   
#endif