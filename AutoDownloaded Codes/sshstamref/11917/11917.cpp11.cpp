#include <bits/stdc++.h>
using namespace std;
int N,M,u;
int S[50005];
int main(){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) cin>>S[i];
    cin>>M;
    if(M<=N) return !printf("%d\n",S[M-1]);
    sort(S,S+N);
    u=unique(S,S+N)-S; S[u]=2e9;
    return !printf("%d\n",min(u+M-N-1,*lower_bound(S,S+u,u)));
}