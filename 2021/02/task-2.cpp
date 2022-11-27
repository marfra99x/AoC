#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream in("input.txt");

    int horizontal_position = 0;
    int depth_position = 0;
    int aim = 0;

    while(!in.eof()){
        string command;
        int number;
        in >> command >> number;

        if(command == "forward"){
            horizontal_position+=number;
            depth_position+=(aim*number);
        }
        if(command == "up")
            aim-=number;
        if(command == "down")
            aim+=number;
    }

    cout << horizontal_position*depth_position << endl;

    return 0;
}