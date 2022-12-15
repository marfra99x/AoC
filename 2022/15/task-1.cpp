#include <bits/stdc++.h>

using namespace std;

int dist(int x1,int y1,int x2,int y2){
    return abs(x2-x1)+abs(y2-y1);
}

int main(){
    ifstream in("input.txt");


    vector<pair<int,int> > sensor;
    vector<pair<int,int> > beacon;

    while(!in.eof()){
        string s;
        char c;
        int x,y;
        in >> s >> s >> c >> c >> x >> s >> c >> c >> y;
        sensor.push_back(make_pair(x,y));
        in >> s >> s >> s >> s >> s >> c >> c >> x >> s >> c >> c >> y;
        beacon.push_back(make_pair(x,y));
    }

    int res = 0;

    int y = 2000000;

    vector<int> distance;

    for(int i=0; i<sensor.size(); i++){
        distance.push_back(dist(sensor[i].first,sensor[i].second,beacon[i].first,beacon[i].second));
    }

    for(int x=-50000000; x<50000000; x++){
        if(find(beacon.begin(), beacon.end(), make_pair(x,y)) != beacon.end())continue; 
        if(find(sensor.begin(), sensor.end(), make_pair(x,y)) != sensor.end())continue; 
        for(int i=0; i<distance.size(); i++){
            if(distance[i] >= dist(sensor[i].first,sensor[i].second,x,y)){
                res++;
                break;
            }
        }
    }

    cout << res << endl;

    return 0;
}
