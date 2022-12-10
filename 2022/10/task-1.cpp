#include <bits/stdc++.h>

using namespace std;


int main(){
    ifstream in("input.txt");

    int res = 0;
    int x = 1;
    int cycle = 0;
    while(!in.eof()){
        string cmd; 
        int num;
        in >> cmd;
        if(cmd == "noop"){
            cycle++;
            if(cycle==20 || cycle==60 || cycle==100 || cycle==140 || cycle==180 || cycle==220){
                res = res + cycle*x;
            }
        }
        else{
            in >> num;
            cycle++;
            if(cycle==20 || cycle==60 || cycle==100 || cycle==140 || cycle==180 || cycle==220){
                res = res + cycle*x;
            }
            cycle++;
            if(cycle==20 || cycle==60 || cycle==100 || cycle==140 || cycle==180 || cycle==220){
                res = res + cycle*x;
            }
            x = x + num;
        }
    }

    cout << res << endl;
    return 0;
}