#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
using namespace std;

int solve(int matrix[][100], int i, int j){
    matrix[i][j] = 9;
    int result = 0;
    if(i+1<100){
        if(matrix[i+1][j] != 9)
            result += 1+solve(matrix, i+1, j);
    }
    if(i-1>=0){
        if(matrix[i-1][j] != 9)
            result += 1+solve(matrix, i-1, j);
    }
    if(j+1<100){
        if(matrix[i][j+1] != 9)
            result += 1+solve(matrix, i, j+1);
    }
    if(j-1>=0){
        if(matrix[i][j-1] != 9)
            result += 1+solve(matrix, i, j-1);
    }
    return result;
}

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

    vector<int> greater_array;

    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(matrix[i][j] != 9){
                greater_array.push_back(1+solve(matrix,i,j));
            }
        }
    }

    sort(greater_array.begin(),greater_array.end(), greater<int>());

    cout << greater_array[0] * greater_array[1] * greater_array[2] << endl;   

    return 0;
}