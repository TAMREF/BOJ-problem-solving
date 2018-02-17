#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef pair<int,int> ii;
int tree[20][100005];
int L,R,N,M;
ii a[100005];
void build(int d, int s, int e){
    if(s>e) return;
    for(int i=s;i<=e;i++) tree[d][i]=tree[d-1][i];
    if(s==e) return;
    int m=(s+e)>>1;
    build(d+1,s,m);
    build(d+1,m+1,e);
    merge(tree[d+1]+s,tree[d+1]+m+1,tree[d+1]+m+1,tree[d+1]+e+1,tree[d]+s);
}
int kth(int k){
    int s=1,e=N,m,c,d=1;
    for(;s<e;++d){
        m=(s+e)>>1,
        c=upper_bound(tree[d+1]+s,tree[d+1]+m+1,R)-lower_bound(tree[d+1]+s,tree[d+1]+m+1,L);
        if(c>=k) e=m;
        else s=m+1,k-=c;
    }
    return s;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++){
        scanf("%d",&a[i].va);
        a[i].vb=i;
    }
    sort(a+1,a+N+1);
    for(int i=1;i<=N;i++) tree[0][i]=a[i].vb;
    build(1,1,N);
    for(int k;M--;){
        scanf("%d%d%d",&L,&R,&k);
        printf("%d\n",a[kth(k)].va);
    }
}