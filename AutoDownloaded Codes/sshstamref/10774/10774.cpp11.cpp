#include <bits/stdc++.h>
using namespace std;
const int mx = 1e6+5;

inline int s(char c){
    return c!='L'?c=='S'?0:1:2;
}

int judge[mx];
int sat[mx];
int J, A, n;
char x;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>J>>A;
    for(int i=0;i<J;i++){
        cin>>x;
        judge[i] = s(x);
    }
    for(int i=0;i<A;i++){
        cin>>x>>n; --n;
        if(s(x) <= judge[n]) sat[n] = 1;
    }
    cout<<accumulate(sat,sat+J,0)<<endl;
}