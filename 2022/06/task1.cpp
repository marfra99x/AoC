#include <fstream>
#include <iostream>
#include <algorithm>
#include <string> 
#include <stack> 

using namespace std;

int main(){
    ifstream in("input.txt");

    string s;
    in >> s;

    for(int i=0; i<s.length(); i++){
        if(s[i] != s[i+1] && s[i] != s[i+2] && s[i] != s[i+3] && s[i+1] != s[i+2] && s[i+1] != s[i+3] && s[i+2] != s[i+3]){
            cout << s[i] << s[i+1] << s[i+2] << s[i+3] << endl;
            cout << i+4 << endl;
            return 0;
        }
    }

    return 0;
}