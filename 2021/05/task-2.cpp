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

        if(x1 == x2 && x2 != y2){
            int greater = max(y1,y2);
            int lower = min(y1,y2);
            for(int i=lower; i<=greater; i++){
                matrix[x1][i]++;
            }
        }
        else if(y1 == y2 && x1 != x2){
            int greater = max(x1,x2);
            int lower = min(x1,x2);
            for(int i=lower; i<=greater; i++){
                matrix[i][y1]++;
            }
        }
        else if(x1 == y1 && x2 == y2){
            int greater = max(x1,x2);
            int lower = min(x1,x2);
            for(int i=lower; i<=greater; i++){
                matrix[i][i]++;
            }
        }
        else if(x1 == y2 && x2 == y1){
            int greater = max(x1,x2);
            int lower = min(x1,x2);
            int diff = greater-lower;
            for(int i=0; i<=diff; i++){
                matrix[lower+i][greater-i]++;
            }
        }
        else{
            int greater_x = max(x1,x2);
            int lower_x = min(x1,x2);
            int diff = greater_x-lower_x;
            for(int i=0; i<=diff; i++){
                int sum_x = i, sum_y = i;
                if(x1 > x2) sum_x*=-1;
                if(y1 > y2) sum_y*=-1;
                // cout << sum_x << " " << sum_y << " " << x1 << " " << x2 << endl;
                matrix[x1+sum_x][y1+sum_y]++;
            }

            // for(int i=0; i<10; i++){
            //     for(int j=0; j<10; j++){
            //         cout << matrix[j][i];
            //     }
            //     cout << endl;
            // }
            // cout << endl;
        }

    }

    int result = 0;
    for(int i=0; i<1000; i++){
        for(int j=0; j<1000; j++){
            // cout << matrix[j][i];
            if(matrix[i][j] > 1){
                result++;
            }
        }
        // cout << endl;
    }

    cout << result << endl;
    return 0;
}