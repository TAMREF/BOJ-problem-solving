#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
const int MX=100005;
pair<int,int> t, Q[MX];
int a[MX], idx[MX], ans[MX];
int main(){
    int n, m; cin>>n>>m;
    int sq=(int)((double)n/sqrt(m));
    for(int i=0;i<n;i++) cin>>a[i];
    for(int x,y,i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        if(x>y) swap(x,y);
        Q[i].va=x-1, Q[i].vb=y-1, idx[i]=i;
    }
    sort(idx,idx+m,[=](int u, int v){return Q[u].va/sq==Q[v].va/sq?Q[u].vb<Q[v].vb:Q[u].va/sq<Q[v].va/sq;});
    for(int i=0,l=Q[idx[0]].va,r=Q[idx[0]].va-1;i<m;i++){
        while(l<Q[idx[i]].va) ans[idx[i]]-=a[l++];
        while(l>Q[idx[i]].va) ans[idx[i]]+=a[--l];
        while(r<Q[idx[i]].vb) ans[idx[i]]+=a[++r];
        while(r>Q[idx[i]].vb) ans[idx[i]]-=a[r--];
        if(i<m-1) ans[idx[i+1]]=ans[idx[i]];
    }
    for(int i=0;i<m;i++) printf("%d\n",ans[i]);
}
