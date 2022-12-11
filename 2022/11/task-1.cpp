#include <bits/stdc++.h>

using namespace std;

struct monkey{
    vector<int> starting_item;
    char operation;
    string operation_num;
    int divisible;
    int true_monkey;
    int false_monkey;
    int inspected;
};

int main(){
    ifstream in("input.txt");
    int n_monkey = 8;
    monkey m[n_monkey];

    int i=0;
    while(!in.eof()){
        string s;
        char c;
        in >> s >> s >> s >> s;
        int num;
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
        in >> s >> s >> s >> s >> s >> num;
        m[i].true_monkey = num;
        in >> s >> s >> s >> s >> s >> num;
        m[i].false_monkey = num;
        m[i].inspected = 0;
        i++;
    }

    // for(int j=0; j<n_monkey; j++){
    //     for(int i=0; i<m[j].starting_item.size(); i++){
    //         cout << m[j].starting_item[i] << " ";
    //     }
    //     cout << endl << m[j].operation << " " << m[j].operation_num << " " << m[j].divisible << " " << m[j].true_monkey << " " << m[j].false_monkey << endl;
    //     cout << "----" << endl;
    // }


    for(int round=0; round<20; round++){
        for(int i=0; i<n_monkey; i++){
            int size = m[i].starting_item.size();
            for(int j=0; j<size; j++){
                int element = m[i].starting_item.back();
                m[i].starting_item.pop_back();
                int number;
                if(m[i].operation_num == "old"){
                    number = element;
                }
                else{
                    number = stoi(m[i].operation_num); 
                }
                if(m[i].operation == '+')element = element + number;
                else element = element * number;
                element = element / 3;

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


    int max1 = numeric_limits<int>::min();
    int max2 = numeric_limits<int>::min();

    for(int i=0; i<n_monkey; i++){
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

    cout << max1*max2 << endl;

    return 0;
}