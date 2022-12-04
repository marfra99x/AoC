#include <fstream>
#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;

int main(){
    ifstream in("input.txt");
    
    int res = 0;
    while(!in.eof()){
        int left1,right1,left2,right2;
        char waste;

        in >> left1 >> waste >> right1 >> waste >> left2 >> waste >> right2;

        if(left1<left2){
            if(left2<=right1)res++;
        }
        else{
            if(left2<left1){
                if(left1<=right2)res++;
            }
            else{
                res++;
            }
        }

    }
    cout << res << endl;
    return 0;
}