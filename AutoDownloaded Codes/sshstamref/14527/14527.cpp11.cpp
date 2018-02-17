#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef pair<int,int> pii;
vector<pii> V;
int ans=0;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,s,e;
    pii z;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>z.vb>>z.va;
        V.push_back(z);
    }
    sort(V.begin(),V.end());
    for(s=0,e=V.size()-1;s<e;){
        ans = max(ans, V[s].va + V[e].va);
        int k = min(V[s].vb, V[e].vb);
        V[s].vb -= k;
        V[e].vb -= k;
        if(!V[s].vb) ++s;
        if(!V[e].vb) --e;
    }
    if(s==e && V[s].vb) ans = max(ans, 2*V[s].va);
    cout<<ans<<'\n';
}