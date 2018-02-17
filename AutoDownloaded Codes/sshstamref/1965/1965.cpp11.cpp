#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> L;
    for(int i=0,x;i<n;i++){
        cin>>x;
        if(L.empty()||x>L.back()) L.push_back(x);
        else *lower_bound(L.begin(),L.end(),x)=x;
    }
    cout<<L.size();
}