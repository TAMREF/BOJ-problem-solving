#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,hp,mp,atk,def,hpe,mpe,atke,defe;
    for(cin>>t;t--;){
        cin>>hp>>mp>>atk>>def>>hpe>>mpe>>atke>>defe;
        cout<<max(1,hp+hpe)+5*max(1,mp+mpe)+2*max(0,atk+atke)+2*(def+defe)<<'\n';
    }
}
