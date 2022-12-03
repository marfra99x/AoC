#include <fstream>
#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;

int main(){
    ifstream in("input.txt");
    
    int res = 0;

    while(!in.eof()){
        string s;
        int v[255];
        for(int i=0; i<255; i++){
            v[i] = 0;
        }
        getline(in,s);
        for(int i=0; i<s.length()/2; i++){
            if(v[s[i]]==0){
                v[s[i]]=1;
            }
        }
        for(int i=s.length()/2; i<s.length(); i++){
            if(v[s[i]]==1)v[s[i]]=2;
        }
        for(int i=0; i<255; i++){
            if(v[i] == 2){
                if(i>='a' && i<='z'){
                    res += i - 'a' + 1;
                }
                if(i>='A' && i<='Z'){
                    res += i - 'A' + 27;
                }
            }
        }
    }
    

    cout << res << endl;

    return 0;
}