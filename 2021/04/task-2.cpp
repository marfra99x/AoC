#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
using namespace std;

bool checkWin(vector<vector<int> > matrix){
    for(int i=0; i<5; i++){
        bool win = true;
        for(int j=0; j<5; j++){
            if(matrix[i][j] != 0){
                win = false;
            }
        }
        if(win) return true;
    }

    for(int j=0; j<5; j++){
        bool win = true;
        for(int i=0; i<5; i++){
            if(matrix[i][j] != 0){
                win = false;
            }
        }
        if(win) return true;
    }

    return false;
}

int main(){
    ifstream in("input.txt");

    vector<int> draw;
    char c = ',';

    while(c==','){
        int num;
        in >> num;
        draw.push_back(num);
        in.get(c);
    }


    vector<vector<int> > matrix;
    matrix.resize(5);
    for(int i=0; i<5; i++)matrix[i].resize(5);

    int row = 0, col = 0;

    int result = 0;
    int count = numeric_limits<int>::min();

    while(!in.eof()){
        in >> matrix[row][col];
        col++;
        if(col == 5){
            row++;
            col = 0;
        }
        if(row == 5){
            for(int i=0; i<draw.size(); i++){
                bool win = false;
                for(int j=0; j<5; j++){
                    for(int k=0; k<5; k++){
                        if(matrix[k][j] == draw[i]){
                            matrix[k][j] = 0;
                        }
                        if(checkWin(matrix)){
                            if(i+1 <= count){
                                win = true;
                                break;
                            }
                            int sum = 0;
                            for(int a=0; a<5; a++){
                                for(int b=0; b<5; b++){
                                    sum += matrix[a][b];
                                }
                            }
                            result = sum*draw[i];
                            count = i+1;
                        }
                    }
                    if(win)break;
                }
                if(win)break;
            }
            row = 0;
            col = 0;
        }
    }

    cout << result << endl;

    return 0;
}