#include <fstream>
#include <iostream>
#include <algorithm>
#include <string> 
#include <vector> 

using namespace std;

int main(){
    ifstream in("input.txt");

    int now = 0;
    vector<int> v;
    while(!in.eof()){
        string s;
        getline (in,s);
        if(s == ""){
            v.push_back(now);
            now = 0;
        }
        else{
            now = now + stoi(s);
        }
    }

    sort(v.begin(),v.end(),greater<int>()),


    cout << v[0]+v[1]+v[2] << endl;


    return 0;
}