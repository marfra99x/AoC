#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
using namespace std;

int main(){
    ifstream in("input.txt");

    int matrix[100][100];

    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            char c;
            in >> c;
            matrix[i][j] = c - '0';
        }
    }
    int res = 0;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            bool lower = true;
            if(i+1<100){
                if(matrix[i+1][j] <= matrix[i][j]){
                    lower = false;
                }
            }
            if(i-1>=0){
                if(matrix[i-1][j] <= matrix[i][j]){
                    lower = false;
                }
            }
            if(j+1<100){
                if(matrix[i][j+1] <= matrix[i][j]){
                    lower = false;
                }
            }
            if(j-1>=0){
                if(matrix[i][j-1] <= matrix[i][j]){
                    lower = false;
                }
            }
            if(lower)res = res + matrix[i][j] + 1;
        }
    }
    cout << res << endl;
    return 0;
}