#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
using namespace std;


int main(){
    ifstream in("input.txt");

    vector<long long> list;

    while(!in.eof()){
        long long a;
        char waste;
        in >> a >> waste;
        list.push_back(a);
    }

    vector<pair<long long,long long> > day;
    day.resize(9);

    for(long long i=0; i<9; i++){
        day[i].first = 0;
        day[i].second = 0;
    }


    for(long long i=0; i<list.size(); i++){
        day[list[i]].first++;
    }

    for(long long i=0; i<256; i++){
        day[(i+2)%7].second = day[i%7].first;
        day[i%7].first += day[i%7].second;
        day[i%7].second = 0;
    }


    long long result = 0;
    for(long long i=0; i<9; i++){
        result = result + day[i].first + day[i].second;
    }

    cout << result << endl;
    return 0;
}