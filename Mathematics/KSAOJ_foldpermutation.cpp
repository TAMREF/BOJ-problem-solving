#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
int seq[505], loc[505];
int n;

bool overlap(pii u, pii v){
    if(v < u) swap(u,v);
    return u.first < v.first && v.first < u.second && u.second < v.second;
}

bool ispaper(){
    vector<pii> I[2];
    for(int i = 1; i < n; i++){
        int x = loc[i], y = loc[i+1];
        if(x > y) swap(x,y);
        pii t = {x,y};
        for(pii &u : I[i & 1]){
            if(overlap(u,t)) return false;
        }
        I[i & 1].push_back(t);
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    for(cin >> t; t--;){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> seq[i];
            loc[seq[i]] = i;
        }
        cout << ispaper() << '\n';
    }
}
