#include <bits/stdc++.h>
using namespace std;
int k,Q,m,n;
int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    for(cin>>k>>Q;Q--;){
        cin>>m>>n;
        if((m>n && m>n+(k-n)/2+1)||(m<=n && n>m+(k-m+1)/2)) puts("0");
        else puts("1");
    }
    return 0;
}