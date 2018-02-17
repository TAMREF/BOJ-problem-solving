#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char S[35];
int len;
ll i;
ll f(ll n){
    if(n<len) return 0;
    ll l = len;
    for(;l<<1 <= n;l<<=1);
    ll ans = f((n+l-1)%l) - 1;
    return ans;
}
int main(){
    scanf("%s %lld",S,&i); len = strlen(S);
    --i;
    //for(i=0;i<12;i++)
    {
        printf("%c\n",S[(f(i)%len + len + i)%len]);
    }
}