#include <bits/stdc++.h>

using namespace std;

struct nodes{
    vector<int> adj;
};

int getIndex(int i, int j, int C){
    return i*C + j;
}

int main(){
    ifstream in("input.txt");

    vector<vector<char> > matrix;

    matrix.resize(41);

    int row = 0;
    while(!in.eof()){
        string s;
        getline(in, s);
        matrix[row].resize(s.length());
        for(int i=0; i<s.length(); i++){
            matrix[row][i] = s[i];
        }
        row++;
    }

    int R = matrix.size();
    int C = matrix[0].size();
    nodes nodo[R*C];
    int start, dest;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(matrix[i][j] == 'E'){
                dest = getIndex(i,j,C);
                matrix[i][j] = '{';
            }
            if(matrix[i][j] == 'S'){
                start = getIndex(i,j,C);
                matrix[i][j] = 'a';
            }
        }
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(i-1>=0 && matrix[i-1][j] <= matrix[i][j]+1){
                nodo[getIndex(i,j,C)].adj.push_back(getIndex(i-1,j,C));
            }
            if(j-1>=0 && matrix[i][j-1] <= matrix[i][j]+1){
                nodo[getIndex(i,j,C)].adj.push_back(getIndex(i,j-1,C));
            }
            if(i+1<R && matrix[i+1][j] <= matrix[i][j]+1){
                nodo[getIndex(i,j,C)].adj.push_back(getIndex(i+1,j,C));
            }
            if(j+1<C && matrix[i][j+1] <= matrix[i][j]+1){
                nodo[getIndex(i,j,C)].adj.push_back(getIndex(i,j+1,C));
            }
        }
    }

    queue<int> q;
    q.push(start);
    int color[R*C];
    int dist[R*C];
    for(int i=0; i<R*C; i++){
        color[i] = 0;
        dist[i] = numeric_limits<int>::max();
    }
    color[start] = 1;
    dist[start] = 0;

    while(!q.empty()){
        int z = q.front();
        q.pop();
        for(int i=0; i<nodo[z].adj.size(); i++){
            if(color[nodo[z].adj[i]] == 0){
                color[nodo[z].adj[i]] = 1;
                dist[nodo[z].adj[i]] = dist[z]+1;
                q.push(nodo[z].adj[i]);
                if(nodo[z].adj[i] == dest){
                    cout << dist[nodo[z].adj[i]] << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}