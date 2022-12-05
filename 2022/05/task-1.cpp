#include <fstream>
#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;

int main(){
    ifstream in("input.txt");
    vector<vector<char> > v;
    for(int i=0; i<10; i++){
        v.resize(10);
    }

    for(int j=0; j<8; j++){
        string s;
        getline(in,s);
        for(int i=1; i<s.length(); i=i+4){
            if(s[i] >= 'A' && s[i]<='Z'){
                v[i/4].push_back(s[i]);
            }
        }
    }
    string s;
    getline(in,s);
    
    for(int j=0; j<9; j++){
        reverse(v[j].begin(), v[j].end());
    }

    while(!in.eof()){
        string waste;
        int num,from,to;
        in >> waste >> num >> waste >> from >> waste >> to;
        from--;
        to--;

        for(int i=0; i<num; i++){
            v[to].push_back(v[from].back());
            v[from].pop_back();
        }
    }

    for(int j=0; j<9; j++){
        cout << v[j].back();
    }

    cout << endl;

    


    return 0;
}