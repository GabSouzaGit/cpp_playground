#ifndef TREE_HPP
    #define TREE_HPP

    #include <string>

    using namespace std;

    void tree(int height, char c){
        int tabing_per_line = height - 1;
        int middle = height - 1;

        for(int x = 0; x < height; x++){
            for(int y = 1; y <= tabing_per_line; y++){
                cout << " ";
            }
            for(int z = 1; z <= 1 + x * 2; z++){
                cout <<  c;
            }

            tabing_per_line--;
            cout << endl;
        }

        for(int x = 0; x < middle - 1; x++){
            cout << " ";
        }

        cout << "| |" << endl;
        
        for(int x = 0; x < middle - 1; x++){
            cout << " ";
        }

        cout << "| |";
    }

#endif