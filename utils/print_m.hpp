#ifndef UTILS_PRINT_MAP_HPP
    #define UTILS_PRINT_MAP_HPP

    #include <map>
    #include <iostream>

    using namespace std;

    template <typename K, typename V>
    void print_m(map<K, V> dict){
        typename map<K, V>::iterator it;
        cout << "{" << endl;
        for(it = dict.begin(); it != dict.end(); ++it){
            cout << "   " << it->first << ": " << it->second << "," << endl;
        }

        cout << "}" << endl;
    }

#endif