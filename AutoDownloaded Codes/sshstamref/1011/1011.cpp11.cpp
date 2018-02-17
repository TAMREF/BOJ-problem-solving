#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,l,pa,h,tam;
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(cin>>a;a--;){
        cin>>l>>pa;
        tam = (int)sqrt(0.1+pa-l);
        if(tam==1) cout<<pa-l<<'\n';
        else cout<<(2*tam-1 + (int)(ceil(1.*(pa-l-tam*tam)/tam)))<<'\n';
    }
}