#ifndef MAZE_RESOLVER_HPP
    #define MAZE_RESOLVER_HPP

    #include <iostream>
    #include <vector>
    #include <stdlib.h>

    using namespace std;

    using Maze = vector<vector<int>>;
    using Position = vector<int>;

    const vector<Position> DIRECTIONS = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    void print_maze(Maze m, bool last){
        vector<char> chars_by_path;
        
        if(last) chars_by_path = {' ', ' ', 'X'};
        else chars_by_path = {'.', '*', '#'};

        for(size_t i = 0; i < m.size(); i++){
            for(size_t j = 0; j < m[i].size(); j++){
                cout << " " << chars_by_path[m[i][j]] << " ";
            }

            cout << endl;
        }

        cout << endl;
    }

    bool maze_resolver(Maze* maze, Position start, Position exit, Position current){
        system("cls");

        print_maze(*maze, false);

        const int LINE = current[0];
        const int COL = current[1];
        
        const bool EXIT_FINDED = LINE == exit[0] && COL == exit[1]; 
        const bool OUT_OF_THE_MAZE = (LINE < 0 || LINE >= maze->size()) || (COL < 0 || COL >= (*maze)[LINE].size());
        
        if(EXIT_FINDED) {
            (*maze)[LINE][COL] = 2;
            system("cls");
            print_maze(*maze, false);

            return true;
        }
        if(OUT_OF_THE_MAZE) return false;
        
        const bool PATH_BLOCKED_OR_TRACED = (*maze)[LINE][COL] == 0 || (*maze)[LINE][COL] == 2;
        
        if(PATH_BLOCKED_OR_TRACED) return false;

        (*maze)[LINE][COL] = 2;

        try {
            for(size_t d = 0; d < DIRECTIONS.size(); d++){
                Position direction = DIRECTIONS[d];
                        
                if(maze_resolver(maze, start, exit, { LINE + (direction[0]), COL + (direction[1]) })){
                    return true;
                }
            }

            (*maze)[LINE][COL] = 1;

            return false;
        }catch(out_of_range e){
            return false;
        }

        return false;
    };
    
#endif