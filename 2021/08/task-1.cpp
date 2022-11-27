#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
using namespace std;


int main(){
    ifstream in("input.txt");
    
    int res = 0;
    while(!in.eof()){
        string s;
        in >> s;
        if(s == "|"){
            for(int i=0; i<4; i++){
                in >> s;
                if(s.length() == 7 || s.length() == 4 || s.length() == 2 || s.length() == 3){
                    res++;
                }
            }    
        }
    }

    cout << res << endl;

    return 0;
}