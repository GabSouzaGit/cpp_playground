#ifndef UTILS_SPLIT_STRING_HPP
    #define UTILS_SPLIT_STRING_HPP

    #include <vector>
    #include <string>

    using namespace std;

    vector<string> split_string(string text, char delimiter){
        vector<string> splitted = {};

        string current = "";
        for(size_t i = 0; i < text.length(); i++){
            if(text[i] == delimiter){
                if(current == "") continue;
                splitted.push_back(current);
                current = "";
                continue;
            }

            current += text[i];
        }

        if(current != "") splitted.push_back(current);

        return splitted;
    }

#endif