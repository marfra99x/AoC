#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
using namespace std;


int main(){
    ifstream in("input.txt");

    vector<int> list;

    while(!in.eof()){
        int a;
        char waste;
        in >> a >> waste;
        list.push_back(a);
    }

    for(int j=0; j<80; j++){
        int size = list.size();
        for(int i=0; i<size; i++){
            list[i]--;
            if(list[i] == -1){
                list[i] = 6;
                list.push_back(8);
            }
        }
    }

    cout << list.size() << endl;


    return 0;
}