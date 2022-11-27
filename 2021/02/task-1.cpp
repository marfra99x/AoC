#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int horizontal_position = 0;
    int depth_position = 0;

    while(!in.eof()){
        string command;
        int number;
        in >> command >> number;

        if(command == "forward")
            horizontal_position+=number;
        if(command == "up")
            depth_position-=number;
        if(command == "down")
            depth_position+=number;
    }

    cout << horizontal_position*depth_position << endl;

    return 0;
}