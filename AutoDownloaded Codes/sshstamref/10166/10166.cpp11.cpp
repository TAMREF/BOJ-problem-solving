#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii> v;
int main(){
    int a, b;
    cin>>a>>b;
    v.push_back({0,1});
    for(int i=a;i<=b;i++)
        for(int j=1;j<i;j++)
            v.push_back({j,i});
    sort(v.begin(),v.end(),[](pii u, pii v)->bool{return u.first*v.second<u.second*v.first;});
    v.erase(unique(v.begin(),v.end(),[](pii u, pii v)->bool{return u.first*v.second==u.second*v.first;}),v.end());
    cout<<v.size()<<endl;
    return 0;
}
