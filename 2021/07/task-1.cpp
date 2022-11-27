#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
using namespace std;


int main(){
    ifstream in("input.txt");
    vector<int> crabs;

    int max_crab = numeric_limits<int>::min();
    int min_crab = numeric_limits<int>::max();

    while(!in.eof()){
        int num;
        char waste;
        in >> num >> waste;
        crabs.push_back(num);
        max_crab = max(max_crab,num);
        min_crab = min(min_crab,num);
    }

    int result = numeric_limits<int>::max();

    for(int i=min_crab; i<=max_crab; i++){
        int sum = 0;
        for(int j=0; j<crabs.size(); j++){
            sum = sum + abs(crabs[j] - i);
        }
        result = min(result,sum);
    }

    cout << result << endl;

    return 0;
}