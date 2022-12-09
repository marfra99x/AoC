#include <bits/stdc++.h>

using namespace std;

void move_tail(int t_x[], int t_y[], int pos, int pred_x, int pred_y){
    int diffx = (pred_x-t_x[pos]);
    int diffy = (pred_y-t_y[pos]);
    if(abs(diffx) <= 1 && abs(diffy) <= 1)return;
    if(diffx != 0){
        t_x[pos] = t_x[pos] + (diffx)/abs(diffx);
    }
    if(diffy!=0){
        t_y[pos] = t_y[pos] + (diffy)/abs(diffy);
    }    
}

int main(){
    ifstream in("input.txt");
    set<pair<int,int> > s;
    s.insert(make_pair(100,100));

    char prev='x'; 
    int prev_m = 0;
    int t_x[9];
    int t_y[9];
    int posx=100,posy=100;

    for(int i=0; i<9; i++){
        t_x[i] = 100;
        t_y[i] = 100;
    }

    while(!in.eof()){
        char move;
        int num;
        in >> move >> num;
        for(int i=0; i<num; i++){
            if(move=='R'){
                posx = posx + 1;
            }
            if(move=='L'){
                posx = posx - 1;
            }
            if(move=='U'){
                posy = posy - 1;
            }
            if(move=='D'){
                posy = posy + 1;
            }

            int pred_x = posx;
            int pred_y = posy;

            for(int j=0; j<9; j++){
                move_tail(t_x,t_y,j,pred_x,pred_y);
                pred_x = t_x[j];
                pred_y = t_y[j];
                if(j==8){
                    s.insert(make_pair(t_x[j],t_y[j]));
                }
            }
        }
    }

    
    cout << s.size() << endl; 
    
    return 0;
}