#include <bits/stdc++.h>
using namespace std;

int I[8][8], J[8][8], K[8][8], rsum[8], csum[8], mark[8][8];
int m,k;

int main(){
    scanf("%d%d",&m,&k);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            scanf("%d",&I[i][j]);
            I[i][j] -= m;
            rsum[i] += I[i][j];
            csum[j] += I[i][j];
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(rsum[i] + csum[j] - I[i][j] & 1){
                mark[i][j] = 1;
                K[i][j] = -1;
                for(int jj = 0; jj < 8; jj++) --J[i][jj];
                for(int ii = 0; ii < 8; ii++) --J[ii][j];
                ++J[i][j];
            }
        }
    }
    for(int i=0;i<8;i++){
        rsum[i] = csum[i] = 0;
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            I[i][j] -= J[i][j];
            rsum[i] += I[i][j];
            csum[j] += I[i][j];
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(mark[i][j] && (rsum[i] + csum[j] - I[i][j])%4 == 2){
                K[i][j] = 1;
            }
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            putchar(K[i][j]<1?K[i][j]?'-':'.':'+');
            putchar(' ');
        }
        puts("");
    }
}