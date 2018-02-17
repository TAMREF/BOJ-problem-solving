#include <bits/stdc++.h>
using namespace std;

char S[105], T[105], U[105];
int  p, q, r;
int D[105][105][105];

void input(){
    scanf("%s%*c%s%*c%s",S,T,U);
    p = strlen(S);
    q = strlen(T);
    r = strlen(U);
}

void pro(){
    for(int i=1;i<=p;i++){
        for(int j=1;j<=q;j++){
            for(int k=1;k<=r;k++){
                if(S[i-1] == T[j-1] && S[i-1] == U[k-1])
                    D[i][j][k] = D[i-1][j-1][k-1] + 1;
                else
                D[i][j][k] = max({D[i-1][j][k], D[i][j-1][k], D[i][j][k-1]});
            }
        }
    }
}

int main(){
    input();
    pro();
    printf("%d\n",D[p][q][r]);
}