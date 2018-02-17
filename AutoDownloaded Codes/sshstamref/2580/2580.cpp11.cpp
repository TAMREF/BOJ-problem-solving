#include <bits/stdc++.h>
using namespace std;
int box[10], row[10], col[10];
int board[9][9];
void fuck(int x){
    if(x==81){
        for(int i=0;i<9;i++,puts("")) for(int j=0;j<9;j++) printf("%d ",board[i][j]);
        exit(0);
    }
    if(board[x/9][x%9]) fuck(x+1);
    else{
        for(int t=1;t<=9;t++){
            if((row[x/9]&1<<t)||(col[x%9]&1<<t)||(box[x/9/3*3+(x%9)/3]&1<<t)) continue;
            (row[x/9]|=1<<t),(col[x%9]|=1<<t),(box[x/9/3*3+(x%9)/3]|=1<<t);
            board[x/9][x%9]=t;
            fuck(x+1);
            (row[x/9]^=1<<t),(col[x%9]^=1<<t),(box[x/9/3*3+(x%9)/3]^=1<<t);
            board[x/9][x%9]=0;
        }
    }
}
int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%d",&board[i][j]);
            if(!board[i][j]) continue;
            row[i]|=(1<<board[i][j]);
            col[j]|=(1<<board[i][j]);
            box[i/3*3+j/3]|=(1<<board[i][j]);
        }
    }
    fuck(0);
}