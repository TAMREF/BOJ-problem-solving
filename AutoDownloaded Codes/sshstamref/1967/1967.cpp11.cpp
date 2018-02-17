#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef pair<int,int> pii;
const int MX=10005;
int V, E;
vector<pii> G[MX];
pii farnode(int x,int px){
    pii ans={0,x};
    for(pii u : G[x]){
        if(u.va==px) continue;
        pii v=farnode(u.va,x);
        ans=max(ans,{v.va+u.vb,v.vb});
    }
    return ans;
}

int diameter(){
    for(int a,b,c=scanf("%d",&V);--V;){
        scanf("%d%d%d",&a,&b,&c);
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    return farnode(farnode(1,0).vb,0).va;
}

int main(){
    cout<<diameter()<<endl;
}
