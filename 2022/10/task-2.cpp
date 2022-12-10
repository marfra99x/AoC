#include <bits/stdc++.h>

using namespace std;


int main(){
    ifstream in("input.txt");

    int res = 0;
    int x = 1;
    int cycle = 0;
    vector<char> v;
    while(!in.eof()){
        string cmd; 
        int num;
        in >> cmd;
        if(cmd == "noop"){
            cycle++;
            if(cycle == x || cycle == x+1 || cycle == x+2){
                v.push_back('#');
            }
            else{
                v.push_back('.');
            }
        }
        else{
            in >> num;
            cycle++;
            if(cycle == x || cycle == x+1 || cycle == x+2){
                v.push_back('#');
            }
            else{
                v.push_back('.');
            }
            cycle++;
            if(cycle == x || cycle == x+1 || cycle == x+2){
                v.push_back('#');
            }
            else{
                v.push_back('.');
            }
            x = x + num;
        }
        cycle = cycle%40;
    }

    for(int i=1; i<=v.size(); i++){
        cout << v[i-1];
        if(i%40 == 0)cout << endl;
    }
    

    return 0;
}