#include <bits/stdc++.h>
using namespace std;

typedef pair<char,int> pci;

list<pci> Q[12];

char I[50005][12];
char B[50005][12];
int r,c;

void input(){
    scanf("%d %d",&r,&c);
    char x;
    for(int i=0;i<r;i++){
        scanf("%*c%s",I[i]);
    }
    for(int i=r-1;i>=0;i--){
        for(int j=0;j<c;j++){
            x = I[i][j];
            if(x == '#'){
                Q[j].emplace_back(x,i);
            }
            if(x == 'a'){
                if(Q[j].empty()) Q[j].emplace_back(x,r-1);
                else Q[j].emplace_back(x,Q[j].back().second-1);
            }
        }
    }
}
void pro(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            B[i][j] = '.';
        }
    }
    for(int j=0;j<c;j++){
        while(!Q[j].empty()){
            pci t = Q[j].front(); Q[j].pop_front();
            B[t.second][j] = t.first;
        }
    }
    for(int i=0;i<r;i++){
        puts(B[i]);
    }
}
int main(){
    input();
    pro();
}