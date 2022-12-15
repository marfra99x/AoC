#include <bits/stdc++.h>

using namespace std;


int main(){
    ifstream in("input.txt");

    char matrix[600][600];

    for(int i=0; i<600; i++){
        for(int j=0; j<600; j++){
            matrix[i][j] = '.';
        }
    }

    matrix[0][500] = '+';
    int max_y = 0;

    while(!in.eof()){
        int x1=-1, y1=-1, x2=-1, y2=-1;
        string s;
        getline(in,s);
        istringstream ss(s);
        while(ss.good()){
            int x,y;
            char c;
            ss >> x >> c >> y >> s;
            max_y = max(y,max_y);
            if(x1==-1){
                x1 = x;
                y1 = y;
            }
            else{
                if(x2==-1){
                    x2 = x;
                    y2 = y;
                }
                else{
                    x1 = x2;
                    y1 = y2;
                    x2 = x;
                    y2 = y;
                }
            }
            if(x1!=-1 && x2!=-1){
                for(int i=min(x1,x2); i<=max(x1,x2); i++){
                    matrix[y1][i] = '#';
                }
                for(int i=min(y1,y2); i<=max(y1,y2); i++){
                    matrix[i][x1] = '#';
                }
            }
        }
    }

    int unit = 1;
    int sx = 500, sy = 0;
    bool finished = false;

    while(!finished){
        if(matrix[sy+1][sx] == '.'){
            sy = sy+1;
        }
        else{
            if(matrix[sy+1][sx+1] != '.' && matrix[sy+1][sx-1] != '.'){
                matrix[sy][sx] = 'O';
                sx = 500;
                sy = 0;
                unit++;
            }
            else{
                if(matrix[sy+1][sx-1] != '.'){
                    sx = sx + 1;
                    sy = sy + 1;
                }
                else{
                    sx = sx - 1;
                    sy = sy + 1;
                }
            }
        }
        if(sy > max_y)break;
    }
    
    cout << unit-1 << endl;

    return 0;
}