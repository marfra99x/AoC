#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    ifstream in("input.txt");

    int numberOfSequence = 1;
    string sequence;
    in >> sequence;
    vector<int> numberOfOne;
    int n = sequence.length();
    numberOfOne.resize(n);

    for(int i=0; i<n; i++){
        if(sequence[i] == '1')numberOfOne[i] = 1;
        else numberOfOne[i] = 0;
    }

    while(!in.eof()){
        in >> sequence;
        for(int i=0; i<n; i++){
            if(sequence[i] == '1')numberOfOne[i]++;
        }
        numberOfSequence++;
    }
        
    string gamma_rate = "";
    string epsilon_rate = "";

    for(int i=0; i<n; i++){
        if(numberOfOne[i] > numberOfSequence/2){
            gamma_rate += '1';
            epsilon_rate += '0';
        }
        else{
            gamma_rate += '0';
            epsilon_rate += '1';
        }
    }


	int gamma_rate_int = stoi(gamma_rate, 0, 2);
	int epsilon_rate_int = stoi(epsilon_rate, 0, 2);

    cout << gamma_rate_int * epsilon_rate_int << endl;

    return 0;
}