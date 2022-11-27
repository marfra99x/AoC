#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
using namespace std;


int main(){
    ifstream in("input.txt");
    vector<long long> crabs;

    long long max_crab = numeric_limits<long long>::min();
    long long min_crab = numeric_limits<long long>::max();

    while(!in.eof()){
        long long num;
        char waste;
        in >> num >> waste;
        crabs.push_back(num);
        max_crab = max(max_crab,num);
        min_crab = min(min_crab,num);
    }

    long long result = numeric_limits<long long>::max();

    for(long long i=min_crab; i<=max_crab; i++){
        long long sum = 0;
        for(long long j=0; j<crabs.size(); j++){
            if(abs(crabs[j] - i) > 0){
                sum = sum + (( abs(crabs[j] - i) * (abs(crabs[j] - i )+1) ) /2);
            }
        }
        result = min(result,sum);
    }

    cout << result << endl;

    return 0;
}