#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ifstream in("input.txt");

    vector<string> sequences;
    string oxigen = "";
    string co2 = "";

    while(!in.eof()){
        string sequence;
        in >> sequence;
        sequences.push_back(sequence);
    }
    sort(sequences.begin(), sequences.end());

    int left = 0;
    int right = sequences.size();
    for(int j=0; j<sequences[0].length(); j++){
        for(int i=left; i<right; i++){
            if(sequences[i][j] == '1'){
                if(i-left < right-i){
                    left = i;
                }
                else{
                    right = i;
                }
                break;
            }
        }
    }

    for(int i=0; i<sequences[0].length(); i++){
        if(sequences[left][i] > sequences[right][i]){
            oxigen = sequences[left];
        }
        if(sequences[right][i] > sequences[left][i]){
            oxigen =  sequences[right];
        }
    }
    int oxigen_int = stoi(oxigen, 0, 2);

    left = 0;
    right = sequences.size();
    for(int j=0; j<sequences[0].length(); j++){
        for(int i=left; i<right; i++){
            if(sequences[i][j] == '1'){
                if(i-left > right-i){
                    left = i;
                }
                else{
                    right = i;
                }
                break;
            }
        }
    }
    for(int i=0; i<sequences[0].length(); i++){
        if(sequences[left][i] < sequences[right][i]){
            co2 = sequences[left];
        }
        if(sequences[right][i] < sequences[left][i]){
            co2 =  sequences[right];
        }
    }
    if(left == right) co2 = sequences[left];
    
    int co2_int = stoi(co2, 0, 2);

    cout << oxigen_int*co2_int << endl;
    return 0;
}