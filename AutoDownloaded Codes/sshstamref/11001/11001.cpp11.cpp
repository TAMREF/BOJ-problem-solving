#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX=100005;
int N, D, T[MX], V[MX];
ll A[MX], v;
void input(){
    scanf("%d %d",&N,&D);
    for(int i=0;i<N;i++) scanf("%d",&T[i]);
    for(int i=0;i<N;i++) scanf("%d",&V[i]);
}
void dp(int s, int e, int p, int q){
    if(s>e) return;
    int m=(s+e)>>1, tk=-1;
    A[m]=LLONG_MIN;
    int ub=min(q,m);
    for(int k=max(p,m-D);k<=ub;k++){
        v=(ll)V[k]-(ll)k*T[m];
        if(v>A[m]){
            A[m]=v; tk=k;
        }
    }
    dp(s,m-1,p,tk);
    dp(m+1,e,tk,q);
}
void output(){
    for(int i=0;i<N;i++) A[i]+=(ll)i*T[i];
    printf("%lld\n",*max_element(A,A+N));
}
int main(){
    input();
    dp(0,N-1,0,N-1);
    output();
}
