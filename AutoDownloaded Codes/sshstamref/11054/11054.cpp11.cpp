#include <bits/stdc++.h>
using namespace std;
int N, u, v, a[1005], b[1005], lis[1005], lds[1005];
vector<int> l, d;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    copy(a,a+N,b); reverse(b,b+N);
    for(int i=0;i<N;i++){
        l.push_back(4<<9);
        u=(int)(lower_bound(l.begin(),l.end(),a[i])-l.begin());
        l[u]=a[i]; lis[i]=u;
        if(l.back()==4<<9) l.pop_back();
        d.push_back(4<<9);
        v=(int)(lower_bound(d.begin(),d.end(),b[i])-d.begin());
        d[v]=b[i]; lds[N-1-i]=v;
        if(d.back()==4<<9) d.pop_back();
    }
    int mx=-1;
    for(int i=0;i<N;i++) mx=max(mx,lis[i]+lds[i]+1);
    printf("%d\n",mx);
}
