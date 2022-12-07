#include <fstream>
#include <iostream>
#include <algorithm>
#include <string> 
#include <stack> 

using namespace std;

struct node{
    int father;
    vector<int> adj;
    vector<int> p;
};

int dfs_edit(node nodo[], int pos){
    int res = 0;
    for(int i=0; i<nodo[pos].adj.size(); i++){
        res += dfs_edit(nodo,nodo[pos].adj[i]);
    }
    for(int i=0; i<nodo[pos].p.size(); i++){
        res += nodo[pos].p[i];
    }
    return res;
}

int main(){
    ifstream in("input.txt");
    node nodo[50000];
    int curr = 0;
    int latest = 0;
    string s;
    in >> s >> s >> s;
    nodo[0].father = -1;

    while(!in.eof()){
        string command;
        in >> command;
        if(command == "$")in >> command;
        if(command == "cd"){
            in >> command;
            if(command == ".."){
                curr = nodo[curr].father;
            }
            else{
                nodo[curr].adj.push_back(latest+1);
                nodo[latest+1].father = curr;
                latest++;
                curr = latest;
            }
        }
        if(command == "ls"){
            while(command != "$" && !in.eof()){
                in >> command;
                if(command[0] >= '1' && command[0] <= '9'){
                    int value = stoi(command);
                    in >> command;
                    nodo[curr].p.push_back(value);
                }
            }
        }
    }
    cout << "end output" << endl;

    int res = 0;
    for(int i=0; i<50000; i++){
        int value = dfs_edit(nodo,i);
        if(value <= 100000)res+=value;
    }

    cout << res << endl;


    return 0;
}