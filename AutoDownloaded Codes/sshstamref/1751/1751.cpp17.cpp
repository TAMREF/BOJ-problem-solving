#include <bits/stdc++.h>
using namespace std;

struct info{
    int r,c,l;
    info(){}
    info(int r,int c, int l):r(r),c(c),l(l){}
};

queue<info> Q;

bool B[305][305];
int r, c;
int ans = 1;

void input(){
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%1d",&B[i][j]);
            if(i && j && i < r-1 && j < c-1) Q.emplace(i,j,1);
        }
    }
    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            if(B[i][j] == B[i-1][j-1] && B[i][j-1] == B[i-1][j]){
                if(i-1 && j-1 && i < r-1 && j < c-1) Q.emplace(i-1,j-1,2);
                ans = 2;
            }
        }
    }
}

void BFS(){
    int lim = min(r,c);
    info t;
    int sr, er, sc, ec, flag;
    while(ans < lim && !Q.empty()){
        t = Q.front(); Q.pop();
        sr = t.r - 1; sc = t.c - 1;
        er = t.r + t.l; ec = t.c + t.l;
        for(int i = 0; i < t.l + 2; i++){
            if(B[sr][sc + i] != B[er][ec - i]){
                goto FAIL;
            }
        }
        for(int i = 0; i < t.l + 2; i++){
            if(B[sr + i][sc] != B[er - i][ec]){
                goto FAIL;
            }
        }
        ans = max(ans, t.l + 2);
        if(sr && sc && er < r-1 && ec < c-1){
            Q.emplace(sr,sc,t.l+2);
        }
        FAIL:
            flag = flag;
    }
    printf("%d\n",ans);
}

int main(){
    input();
    BFS();
}
