#include <bits/stdc++.h>
using namespace std;
int tam[40005];
vector<int> L;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>tam[i];
    for(int i=0;i<n;i++){
        if(!i || L.back()<tam[i]) L.push_back(tam[i]);
        else *lower_bound(L.begin(),L.end(),tam[i])=tam[i];
    }
    cout<<L.size()<<endl;
    return 0;
}