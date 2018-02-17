#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;

typedef pair<int,int> pii;
const int mod = 40000;

int n;
pii tam[200005];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tam[i].va >> tam[i].vb;
        if(!tam[i].va && !tam[i].vb){
            --i; --n;
            continue;
        }
    }
    sort(tam,tam+n,[](pii u, pii v){
            return u.va * v.vb > v.va * u.vb;
        });
    int t = 0;
    for(int i=0;i<n;i++){
        t = (t + tam[i].va * t + tam[i].vb) % mod;
    }
    cout<<t<<endl;
}