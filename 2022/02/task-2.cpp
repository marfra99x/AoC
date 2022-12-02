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
        if(me == 'X'){ 
            if(him == 'B' || him == 'C'){
                res = res + him - 'A';
            }
            else{
                res = res + 3;
            }
        }
        if(me == 'Y'){ 
            res = res + 3;
            res = res + him - 'A' + 1;
        }
        if(me == 'Z'){ 
            res = res + 6;
            if( him == 'A' || him == 'B'){
                res = res + him - 'A' + 2;
            }
            else{
                res = res + 1;
            }
        }

    }
    cout << res << endl;

    return 0;
}