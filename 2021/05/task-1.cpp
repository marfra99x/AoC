#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
using namespace std;


int main(){
    ifstream in("input.txt");

    int matrix[1000][1000];

    for(int i=0; i<1000; i++){
        for(int j=0; j<1000; j++){
            matrix[i][j] = 0;
        }
    }

    while(!in.eof()){
        char waste;
        int x1,x2,y1,y2;
        in >> x1;
        in >> waste;
        in >> y1;
        in >> waste >> waste;
        in >> x2;
        in >> waste; 
        in >> y2;

        if(x1 == x2){
            int greater = max(y1,y2);
            int lower = min(y1,y2);
            for(int i=lower; i<=greater; i++){
                matrix[x1][i]++;
            }
        }
        if(y1 == y2){
            int greater = max(x1,x2);
            int lower = min(x1,x2);
            for(int i=lower; i<=greater; i++){
                matrix[i][y1]++;
            }
        }
    }

    int result = 0;
    for(int i=0; i<1000; i++){
        for(int j=0; j<1000; j++){
            if(matrix[i][j] > 1){
                result++;
            }
        }
    }

    cout << result << endl;
    return 0;
}