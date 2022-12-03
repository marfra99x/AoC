#include <fstream>
#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;

int main(){
    ifstream in("input.txt");
    
    int res = 0;

    while(!in.eof()){
        string s1, s2, s3;
        int v1[255], v2[255], v3[255];
        for(int i=0; i<255; i++){
            v1[i] = 0;
            v2[i] = 0;
            v3[i] = 0;
        }
        getline(in,s1);
        getline(in,s2);
        getline(in,s3);

        for(int i=0; i<s1.length(); i++){
            if(v1[s1[i]]==0){
                v1[s1[i]]=1;
            }
        }
        for(int i=0; i<s2.length(); i++){
            if(v2[s2[i]]==0){
                v2[s2[i]]=1;
            }
        }
        for(int i=0; i<s3.length(); i++){
            if(v3[s3[i]]==0){
                v3[s3[i]]=1;
            }
        }
        for(int i=0; i<255; i++){
            if(v1[i]+v2[i]+v3[i] == 3){
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