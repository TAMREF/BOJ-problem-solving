#include <bits/stdc++.h>
using namespace std;
unordered_set<int> game;
unordered_set<int> footprint;
int pow3[9] = {1,3,9,27,81,243,729,2187,6561};

int bo[9];

inline int check(int st, int i){
    return (st/pow3[i])%3;
}

void display(int st){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            putchar(".XO"[check(st,3*i+j)]);
        }
        puts("");
    }
}

inline bool gameset(int st){
    for(int i=0;i<9;i++) bo[i] = check(st, i);
    for(int i=0;i<3;i++){
        if(bo[i] && bo[i]==bo[i+3] && bo[i]==bo[i+6]) return true;
        if(bo[3*i] && bo[3*i]==bo[3*i+1] && bo[3*i]==bo[3*i+2]) return true;
    }
    if(bo[0] && bo[0] == bo[4] && bo[0] == bo[8]){
        //puts("048");
        return true;
    }
    if(bo[2] && bo[2] == bo[4] && bo[2] == bo[6]){
        //puts("246");
        return true;
    }
    return false;
}

void play(int st, int turn){
    if(gameset(st)){
        game.insert(st);
        return;
    }
    if( game.find(st) != game.end() ) return;
    game.insert(st);
    for(int i=0;i<9;i++){
        if(!check(st,i)){
            play(st + turn*pow3[i], 3-turn);
        }
    }
}



int main(){
    play(0,1);
    //printf("%d\n",game.size());
    int n,x;
    char S[10];
    for(scanf("%d",&n);n--;){
        scanf("%*c%s\n%s\n%s%*c",S,S+3,S+6);
        //puts(S);
        x = 0;
        for(int i=0;i<9;i++){
            x += pow3[i] * (S[i]!='.'?S[i]=='X'?1:2:0);
        }
        puts(game.find(x)!=game.end()?"yes":"no");
    }
}
