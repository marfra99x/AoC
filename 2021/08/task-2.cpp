#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
using namespace std;

bool isSubsetOf(string subset,string set){
    for(int i=0; i<subset.length(); i++)
    if (set.find(subset[i]) == string::npos){
        return false;
    }
    return true;
}

bool isSameSet(string a,string b){
    if(a.length()!=b.length())return false;
    for(int i=0; i<a.length(); i++)
    if (b.find(a[i]) == string::npos){
        return false;
    }
    return true;
}

int main(){
    ifstream in("input.txt");
    
    vector<string> result;
    /*
    0 -> 6
    1 -> 2*
    2 -> 5*
    3 -> 5*
    4 -> 4*
    5 -> 5*
    6 -> 6
    7 -> 3*
    8 -> 7*
    9 -> 6
    */

    int res = 0;
    string zero="",one="",two="",three="",four="",five="",six="",seven="",eight="",nine="";
    vector<string> sequences;
    while(!in.eof()){
        string s;
        in >> s;
        sequences.push_back(s);
        if(s.length() == 4){
            four = s;
        }
        if(s.length() == 2){
            one = s;
        }
        if(s.length() == 3){
            seven = s;
        }
        if(s.length() == 7){
            eight = s;
        }
        if(s == "|"){
            for(int i=0; i<sequences.size(); i++){
                for(int j=0; j<sequences.size(); j++){
                    if(sequences[j].length() == 6){
                        if(!isSubsetOf(one,sequences[j]))six = sequences[j];
                        else{
                            if(isSubsetOf(four,sequences[j]))nine = sequences[j];
                            else zero = sequences[j];
                        }
                    }
                    if(sequences[j].length() == 5){
                        if(isSubsetOf(one,sequences[j]))three = sequences[j];
                        else{
                            if(nine!=""){
                                    if(isSubsetOf(sequences[j],nine))five = sequences[j];
                                    else two = sequences[j];
                                }
                        } 
                    }
                }    
            }
            string result = "";
            for(int i=0; i<4; i++){
                in >> s;
                if(isSameSet(s,zero))result+="0";
                if(isSameSet(s,one))result+="1";
                if(isSameSet(s,two))result+="2";
                if(isSameSet(s,three))result+="3";
                if(isSameSet(s,four))result+="4";
                if(isSameSet(s,five))result+="5";
                if(isSameSet(s,six))result+="6";
                if(isSameSet(s,seven))result+="7";
                if(isSameSet(s,eight))result+="8";
                if(isSameSet(s,nine))result+="9";
            }
            res += stoi(result);
            zero="",one="",two="",three="",four="",five="",six="",seven="",eight="",nine="";
            sequences.clear();
        }
    }

    cout << res << endl;

    return 0;
}