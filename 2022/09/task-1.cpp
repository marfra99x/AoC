#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream in("input.txt");
    set<pair<int,int> > s;
    s.insert(make_pair(100,100));

    char prev='x'; 
    int prev_m = 0;
    int t_x=100, t_y = 100;
    int posx=100,posy=100;

    while(!in.eof()){
        char move;
        int num;
        in >> move >> num;
        for(int i=0; i<num; i++){
            if(move=='R'){
                int new_x = posx + 1;
                if(abs(new_x-t_x) > 1){
                    t_x = posx;
                    t_y = posy;
                    s.insert(make_pair(t_x,t_y));
                }
                posx = new_x;
            }
            if(move=='L'){
                int new_x = posx-1;
                if(abs(new_x-t_x) > 1){
                    t_x = posx;
                    t_y = posy;
                    s.insert(make_pair(t_x,t_y));
                }
                posx = new_x;
            }
            if(move=='U'){
                int new_y = posy - 1;
                if(abs(new_y-t_y) > 1){
                    t_x = posx;
                    t_y = posy;
                    s.insert(make_pair(t_x,t_y));
                }
                posy = new_y;
            }
            if(move=='D'){
                int new_y = posy + 1;
                if(abs(new_y-t_y) > 1){
                    t_x = posx;
                    t_y = posy;
                    s.insert(make_pair(t_x,t_y));
                }
                posy = new_y;
            }
        }
    }
    
    cout << s.size() << endl; 
    
    return 0;
}