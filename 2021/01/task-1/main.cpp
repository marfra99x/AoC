#include <fstream>
#include <iostream>
using namespace std;
int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int current_measurement;
    in >> current_measurement;
    int sol = 0;

    while(!in.eof()){
        int new_measurement;
        in >> new_measurement;
        if(new_measurement > current_measurement){
            sol++;
        }
        current_measurement = new_measurement;
    }
    cout << sol;
    return 0;
}
