#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
const int MX=100005;
int K[1000005], a[MX], idx[MX];
long long f[MX];
pair<int,int> q[MX];
int main(){
    int n, t, sq;
    scanf("%d %d",&n,&t);
    sq=(int)((double)n/sqrt(t));
    if(!sq) sq=(int)sqrt(n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<t;idx[i]=i,i++) scanf("%d %d",&q[i].va,&q[i].vb), --q[i].va, --q[i].vb;
    sort(idx,idx+t,[=](int u, int v){return q[u].va/sq==q[v].va/sq?q[u].vb<q[v].vb:q[u].va<q[v].va;});
    for(int i=0,l=q[idx[0]].va,r=q[idx[0]].va-1;i<t;i++){
        while(l<q[idx[i]].va) f[idx[i]]-=(ll)a[l]*(2LL*(--K[a[l++]])+1);
        while(l>q[idx[i]].va) f[idx[i]]+=(ll)a[--l]*(2LL*(++K[a[l]])-1);
        while(r<q[idx[i]].vb) f[idx[i]]+=(ll)a[++r]*(2LL*(++K[a[r]])-1);
        while(r>q[idx[i]].vb) f[idx[i]]-=(ll)a[r]*(2LL*(--K[a[r--]])+1);
        if(i<t-1) f[idx[i+1]]=f[idx[i]];
    }
    for(int i=0;i<t;i++) printf("%lld\n",f[i]);
}
