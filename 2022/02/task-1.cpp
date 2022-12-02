#include <fstream>
#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;

int main(){
    ifstream in("input.txt");
    int res = 0;

    while(!in.eof()){
        char him,me;
        in >> him >> me;
        if(him-'A' == me-'X')res+=3;
        if(him=='A' && me=='Y')res+=6;
        if(him=='B' && me=='Z')res+=6;
        if(him=='C' && me=='X')res+=6;
        res+=(me-'X'+1);
    }
    cout << res << endl;

    return 0;
}