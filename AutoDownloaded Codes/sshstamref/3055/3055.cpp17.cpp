#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int inf = 1e3;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

char B[55][55];

int D[55][55], F[55][55];
int r, c, dr, dc;

queue<pii> W, H;

void input(){
    scanf("%d %d",&r,&c);
    for(int i=1;i<=r;i++) for(int j=1;j<=c;j++) D[i][j] = F[i][j] = inf;
    for(int i=1;i<=r;i++){
        scanf("%*c");
        for(int j=1;j<=c;j++){
            scanf("%c",&B[i][j]);
            if(B[i][j] == '*'){
                F[i][j] = 0;
                W.emplace(i,j);
            }else if(B[i][j] == 'S'){
                D[i][j] = 0;
                H.emplace(i,j);
            }else if(B[i][j] == 'D'){
                dr = i;
                dc = j;
            }
        }
    }
}

void waterflow(){
    pii t;
    int nr, nc, d;
    while(!W.empty()){
        t = W.front(); W.pop();
        d = F[t.first][t.second];
        for(int p=0;p<4;p++){
            nr = t.first + dx[p];
            nc = t.second + dy[p];
            if(B[nr][nc] == 'D' || B[nr][nc] == 'X') continue;
            if(F[nr][nc] > d + 1){
                F[nr][nc] = d + 1;
                W.emplace(nr,nc);
            }
        }
    }
}

void hedge(){
    pii t;
    int nr, nc, d;
    while(!H.empty()){
        t = H.front(); H.pop();
        d = D[t.first][t.second];
        for(int p=0;p<4;p++){
            nr = t.first + dx[p];
            nc = t.second + dy[p];
            if(B[nr][nc] == 'X') continue;
            if(D[nr][nc] > d + 1 && F[nr][nc] > d + 1){
                D[nr][nc] = d + 1;
                H.emplace(nr,nc);
            }
        }
    }
}

int main(){
    input();
    waterflow();
    hedge();
    if(D[dr][dc] == inf){
        puts("KAKTUS");
    }else{
        printf("%d\n",D[dr][dc]);
    }
}
