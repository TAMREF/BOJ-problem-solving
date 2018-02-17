#include <bits/stdc++.h>
using namespace std;
const int mx=100005;
int np[mx];
struct FWtree{
    int n, a[2*mx+1];
    void init(int N){
        n=N;
        memset(a,0,sizeof(a));
    }
    int sum(int i){
        int s=0;
        for(int j=i;j;j-=j&-j) s+=a[j];
        return s;
    }
    void upd(int i,int v){
        for(int j=i;j<=n;j+=j&-j) a[j]+=v;
    }
} F;
int main(){
    int T,N,M;
    for(scanf("%d",&T);T--;){
        scanf("%d%d",&N,&M);
        F.init(N+M);
        for(int i=M+1;i<=M+N;i++){
            F.upd(i,1);
            np[i-M]=i;
        }
        for(int i=0,x;i<M;i++){
            scanf("%d",&x);
            F.upd(np[x],-1);
            printf("%d ",F.sum(np[x]));
            F.upd(np[x]=M-i,1);
        }
        puts("");
    }
}