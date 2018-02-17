#include <bits/stdc++.h>
using namespace std;
const int MX=1005;
char SA[MX][MX];
int N, ord[MX];
int main(){
    scanf("%s",SA[0]);
    N=strlen(SA[0]);
    for(int i=0;++i<N;ord[i]=i) copy(SA[0]+i,SA[0]+N,SA[i]);
    sort(ord,ord+N,[](int u, int v)->bool{
         for(int i=0,m=min(N-u,N-v);i<m;i++)
            if(SA[u][i]!=SA[v][i]) return SA[u][i]<SA[v][i];
         return u>v;
    });
    for(int i=0;i<N;i++) puts(SA[ord[i]]);
}
