#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll c1;
    cin>>c1;
    ll cnt = 1;
    while(c1>1){
        c1 = (c1&1 ? c1*3+1 : c1>>1);
        ++cnt;
    }
    cout<<cnt<<endl;
}