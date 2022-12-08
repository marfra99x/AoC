#include <fstream>
#include <iostream>
#include <algorithm>
#include <string> 
#include <stack> 
#include <limits> 

using namespace std;

bool is_left_visible(vector<vector<int> > matrix, int i, int j){
    for(int a=j; a>=0; a--){
        if(matrix[i][a] >= matrix[i][j] && a!=j)return false;
    }
    return true;
}
bool is_right_visible(vector<vector<int> > matrix, int i, int j){
    for(int a=j; a<matrix.size(); a++){
        if(matrix[i][a] >= matrix[i][j] && a!=j)return false;
    }
    return true;
}
bool is_up_visible(vector<vector<int> > matrix, int i, int j){
    for(int a=i; a>=0; a--){
        if(matrix[a][j] >= matrix[i][j] && a!=i)return false;
    }
    return true;
}
bool is_down_visible(vector<vector<int> > matrix, int i, int j){
    for(int a=i; a<matrix.size(); a++){
        if(matrix[a][j] >= matrix[i][j] && a!=i)return false;
    }
    return true;
}

bool is_visible(vector<vector<int> > matrix, int i, int j){
    if(i==0 || j==0 || i==matrix.size()-1 || j==matrix.size()-1) return true;   

    return is_left_visible(matrix,i,j) || is_right_visible(matrix,i,j) || is_down_visible(matrix,i,j) || is_up_visible(matrix,i,j);
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
            if(is_visible(matrix,i,j))res++;
        }
    }

    cout << res << endl;
    return 0;
}