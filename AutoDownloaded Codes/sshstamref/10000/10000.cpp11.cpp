#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

stack<pii> S;
pii C[300003];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin>>n;
    int reg = n+1;
    for(int i=0,x,r;i<n;i++){
        cin>>x>>r;
        C[i] = {x-r,x+r};
    }
    sort(C,C+n,[](pii u, pii v){return u.first==v.first?u.second>v.second:u.first<v.first;});
    for(int i=1;i<n;i++){
        if(C[i].first == C[i-1].first){
            S.emplace(C[i].second,C[i-1].second);
        }else{
            while(!S.empty() && S.top().first < C[i].first) S.pop();
            if(S.empty() || S.top().first > C[i].first) continue;
            pii t = S.top(); S.pop();
            if(t.second == C[i].second) ++reg;
            else S.emplace(C[i].second, t.second);
        }
    }
    cout<<reg<<'\n';
}
