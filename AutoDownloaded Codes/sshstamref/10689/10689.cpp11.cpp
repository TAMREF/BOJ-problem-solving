#include <bits/stdc++.h>
using namespace std;
int D[100005];
unordered_map<int,int> m;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,n,x; cin>>t;
    for(int f=1;f<=t;f++){
        m.clear(); x=1;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>D[i];
            if(!m[D[i]]) m[D[i]]=i+1;
        }
        for(auto u : m) x=max(x,u.second);
        cout<<"Case "<<f<<": "<<x<<'\n';
    }
    return 0;
}