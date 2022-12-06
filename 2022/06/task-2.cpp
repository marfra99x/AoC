#include <fstream>
#include <iostream>
#include <algorithm>
#include <string> 
#include <stack> 

using namespace std;

bool check(string s, int pos){
    for(int i=pos; i<pos+14; i++){
        for(int j=i+1; j<pos+14; j++){
            if(s[i] == s[j])return false;
        }
    }
    return true;
}

int main(){
    ifstream in("input.txt");

    string s;
    in >> s;

    for(int i=0; i<s.length(); i++){
        if(check(s,i)){
            cout << i+14 << endl;
            return 0;
        }
    }

    return 0;
}