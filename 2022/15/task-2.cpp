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

    long long a = 4000000;

    vector<int> distance;

    for(int i=0; i<sensor.size(); i++){
        distance.push_back(dist(sensor[i].first,sensor[i].second,beacon[i].first,beacon[i].second));
    }

    for(int i=0; i<sensor.size(); i++){
        int x = 0;
        int y = -distance[i]-1;
        while(y <= distance[i]+1){
            bool bigger = true;
            for(int k=0; k<distance.size(); k++){
                if(distance[k] >= dist(sensor[k].first,sensor[k].second,sensor[i].first+x,sensor[i].second+y) 
                    || sensor[i].first+x<0 || sensor[i].first+x>a || sensor[i].second+y<0 || sensor[i].second+y>a ){
                    bigger = false;
                    break;
                }
            }
            if(bigger){
                cout << (sensor[i].first+x)*a + (sensor[i].second+y) << endl;
                return 0;
            }
            x--;
            y++;
        }
    }

    cout << "end" << endl;


    return 0;
}
