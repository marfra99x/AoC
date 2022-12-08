#include <fstream>
#include <iostream>
#include <algorithm>
#include <string> 
#include <stack> 
#include <limits> 

using namespace std;

int number_of_visible_left(vector<vector<int> > matrix, int i, int j){
    int res = 0;
    for(int a=j-1; a>=0; a--){
        if(matrix[i][a] >= matrix[i][j])return res+1;
        else res++;
    }
    return res;
}
int number_of_visible_right(vector<vector<int> > matrix, int i, int j){
    int res = 0;
    for(int a=j+1; a<matrix.size(); a++){
        if(matrix[i][a] >= matrix[i][j])return res+1;
        else res++;
    }
    return res;
}
int number_of_visible_up(vector<vector<int> > matrix, int i, int j){
    int res = 0;
    for(int a=i-1; a>=0; a--){
        if(matrix[a][j] >= matrix[i][j])return res+1;
        else res++;
    }
    return res;
}
int number_of_visible_down(vector<vector<int> > matrix, int i, int j){
    int res = 0;
    for(int a=i+1; a<matrix.size(); a++){
        if(matrix[a][j] >= matrix[i][j])return res+1;
        else res++;
    }
    return res;
}

int is_visible(vector<vector<int> > matrix, int i, int j){
    return number_of_visible_left(matrix,i,j) * number_of_visible_right(matrix,i,j) * number_of_visible_up(matrix,i,j) * number_of_visible_down(matrix,i,j);
}

int main(){
    ifstream in("input.txt");

    vector<vector<int> > matrix;

    while(!in.eof()){
        string s; 
        getline(in, s);
        matrix.resize(matrix.size()+1);

        for(int i=0; i<s.length(); i++){
            matrix[matrix.size()-1].push_back(s[i]-'0');
        }
    }

    int res = 0;
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix.size(); j++){
            res = max(res, is_visible(matrix,i,j));
        }
    }

    cout << res << endl;
    return 0;
}