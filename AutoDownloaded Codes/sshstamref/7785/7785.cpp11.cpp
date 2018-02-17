#include <bits/stdc++.h>
using namespace std;
string X;
unordered_set<string> u;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    for(cin>>n,getline(cin,X);n--;){
        getline(cin,X);
        if(X.back()=='r') u.insert(X.substr(0,X.size()-6));
        else u.erase(X.substr(0,X.size()-6));
    }
    vector<string> V;
    for(string k : u){
        V.push_back(k);
    }
    sort(V.begin(),V.end(),[](string &u, string &v){
            return !lexicographical_compare(u.begin(),u.end(),v.begin(),v.end());
        });
    for(string &k : V) cout<<k<<'\n';
}