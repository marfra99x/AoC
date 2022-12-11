#include <bits/stdc++.h>

using namespace std;

struct monkey{
    vector<long long> starting_item;
    char operation;
    string operation_num;
    long long divisible;
    long long true_monkey;
    long long false_monkey;
    long long inspected;
};


long long multiple_all_divider(vector<long long> arr, long long n){
    long long result = 1;
    for (long long i = 0; i < n; i++){
        result *= arr[i];
    }
    return result;
}
int main(){
    ifstream in("input.txt");
    long long n_monkey = 8;
    monkey m[n_monkey];
    long long reduction = 1;
    vector<long long> arr;

    long long i=0;
    while(!in.eof()){
        string s;
        char c;
        in >> s >> s >> s >> s;
        long long num;
        c = ',';
        while(c == ','){
            in >> num >> c; 
            m[i].starting_item.push_back(num);
        }
        in >> s;
        in >> s;
        in >> s >> s >> c >> s;
        m[i].operation = c;
        m[i].operation_num = s;
        in >> s >> s >> s >> num;
        m[i].divisible = num;
        arr.push_back(num);
        in >> s >> s >> s >> s >> s >> num;
        m[i].true_monkey = num;
        in >> s >> s >> s >> s >> s >> num;
        m[i].false_monkey = num;
        m[i].inspected = 0;
        i++;
    }

    reduction = multiple_all_divider(arr,arr.size());
    cout << arr.size() << endl;


    for(long long round=0; round<10000; round++){
        for(long long i=0; i<n_monkey; i++){
            long long size = m[i].starting_item.size();
            for(long long j=0; j<size; j++){
                long long element = m[i].starting_item.back();
                m[i].starting_item.pop_back();
                long long number;
                if(m[i].operation_num == "old"){
                    number = element;
                }
                else{
                    number = stoi(m[i].operation_num); 
                }
                if(m[i].operation == '+')element = element + number;
                else element = element * number;

                element = element % reduction;

                if(element % m[i].divisible == 0){
                    m[m[i].true_monkey].starting_item.push_back(element);
                }
                else{
                    m[m[i].false_monkey].starting_item.push_back(element);
                }
                m[i].inspected++;
            }
        }
    }

    long long max1 = numeric_limits<long long>::min();
    long long max2 = numeric_limits<long long>::min();

    for(long long i=0; i<n_monkey; i++){
        if(m[i].inspected > max1){
            max2 = max1;
            max1 = m[i].inspected;
        }
        else{
            if(m[i].inspected>max2){
                max2 = m[i].inspected;
            }
        }
    }

    cout << "reduction: " << reduction << endl;
    cout << max1 << " " << max2 << endl;
    cout << max1*max2 << endl;

    return 0;
}