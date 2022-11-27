#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    int sol = 0;
    vector<int> v;
    v.resize(4);
    in >> v[0] >> v[1] >> v[2];

    while(!in.eof()){
        in >> v[3];
        if(v[3] > v[0]){
            sol++;
        }
        v[0] = v[1];
        v[1] = v[2];
        v[2] = v[3];
    }
    cout << sol << endl;
    return 0;
}
