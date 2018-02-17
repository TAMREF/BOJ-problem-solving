#include <bits/stdc++.h>
using namespace std;
vector<string> g[51];
int main(){
    cin.sync_with_stdio(false); cin.tie(0);
    int n;
    string x;
    cin>>n;
    for(getline(cin,x);n--;){
        getline(cin,x);
        g[x.size()].push_back(x);
    }
    for(int i=1;i<=50;i++){
        sort(g[i].begin(),g[i].end());
        g[i].erase(unique(g[i].begin(),g[i].end()),g[i].end());
        for(string &u : g[i]) cout<<u<<'\n';
    }
    return 0;
}