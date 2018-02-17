#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll D[10005], E[10005];
int C[105], M[105],N,T;
int main(){
    scanf("%d%d",&N,&T);
    for(int i=0;i<N;i++) scanf("%d",&M[i]);
    for(int i=0;i<N;i++) scanf("%d",&C[i]);
    for(int i=0;i<N;i++){
        for(int c=0;c+C[i]<=1e4;c++){
            if(D[c]) E[c+C[i]]=max(D[c+C[i]],D[c]+M[i]);
        }
        E[C[i]]=max(D[C[i]],(ll)M[i]);
        copy(E,E+10001,D);
    }
    for(int c=0;c<=1e4;c++) if(D[c]>=T) return !printf("%d\n",c);
}