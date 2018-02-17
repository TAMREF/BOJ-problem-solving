#include <bits/stdc++.h>
using namespace std;

unsigned int cXor(unsigned int x){
    unsigned int ans = 0;
    for(int i=31;i--;){
        unsigned int tmp = x & (1u<<i+1)-1;
        if( (tmp & 1) == 0 && ( tmp >= 1u<<i ) ) ans |= 1<<i;
    }
    if( (x & 3) % 3){
        ans |= 1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    unsigned int t,s,e;
    for(cin>>t;t--;){
        cin>>s>>e;
        cout<<(cXor(e)^cXor(s-1))<<'\n';
    }
}
