#include <bits/stdc++.h>
using namespace std;
const int mx=32005;
vector<int> G[mx];
int V,E,a,b,t,ideg[mx];
priority_queue<int,vector<int>,greater<int>> pQ;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(cin>>V>>E;E--;){
        cin>>a>>b;
        G[a].push_back(b);
        ++ideg[b];
    }
    for(int i=1;i<=V;i++) if(!ideg[i]) pQ.push(i);
    for(;!pQ.empty();){
        t=pQ.top(); pQ.pop();
        cout<<t<<' ';
        for(int u : G[t]){
            --ideg[u];
            if(!ideg[u]) pQ.push(u);
        }
    }
    cout<<endl;
}