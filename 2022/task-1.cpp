#include <fstream>
#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;

int main(){
    ifstream in("input.txt");

    int res = 0;
    int now = 0;
    while(!in.eof()){
        string s;
        getline (in,s);
        if(s == ""){
            res = max(res,now);
            now = 0;
        }
        else{
            now = now + stoi(s);
        }
    }

    cout << res << endl;


    return 0;
}