#include <bits/stdc++.h>
using namespace std;
char S[1005][55];
int n,m;
int U[256];

void input(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n+n;i++){
        scanf("%*c%s",S[i]);
    }
    U['A']=0; U['C']=1; U['T']=2; U['G']=3;
}

int work(){
    unsigned long long G=0;
    int cnt = 0;
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            for(int k=j+1;k<m;k++){
                G = 0;
                for(int t=0;t<n;t++){
                    G |= 1ULL<<((U[S[t][i]]<<4) + (U[S[t][j]]<<2) + U[S[t][k]]);
                }
                for(int t=n;t<n+n;t++){
                    if(G & 1ULL<<((U[S[t][i]]<<4) + (U[S[t][j]]<<2) + U[S[t][k]])) goto FAIL;
                }
                ++cnt;
                FAIL:
                   cnt = cnt;
            }
        }
    }
    return cnt;
}
int main(){
    input();
    printf("%d\n",work());
}