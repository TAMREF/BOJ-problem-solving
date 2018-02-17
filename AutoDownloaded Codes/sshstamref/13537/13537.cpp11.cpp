#include <bits/stdc++.h>
#define ub(x,k) (int)(upper_bound(x.begin(),x.end(),k)-x.begin())
using namespace std;
const int MX=131072;
int N, M, a[MX];
vector<int> seg[2*MX];
void input(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
}
void build(int n, int s, int e){
    if(s==e){
        seg[n].push_back(a[s]);
        return;
    }
    seg[n].assign(e-s+1,0);
    int m = (s+e)>>1;
    build(n<<1,s,m); build(n<<1|1,m+1,e);
    merge(seg[n<<1].begin(),seg[n<<1].end(),seg[n<<1|1].begin(),seg[n<<1|1].end(),seg[n].begin());
}
int getval(int n, int s, int e, int l, int r, int t){
    if(l>e||r<s) return 0;
    if(l<=s&&e<=r) return seg[n].size()-ub(seg[n],t);
    int m = (s+e)>>1;
    return getval(n<<1,s,m,l,r,t)+getval(n<<1|1,m+1,e,l,r,t);
}
int main(){
    input(); int i,j,k;
    build(1,0,N-1);
    for(scanf("%d",&M);M--;){
        scanf("%d%d%d",&i,&j,&k);
        printf("%d\n",getval(1,0,N-1,i-1,j-1,k));
    }
    return 0;
}
