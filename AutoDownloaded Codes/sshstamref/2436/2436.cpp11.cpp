#include <bits/stdc++.h>
using namespace std;
long long l,g;
int main(){
    scanf("%lld%lld",&g,&l); l/=g;
    long long sq=1;
    for(;sq*sq<l;++sq);
    for(long long i=sq;i;i--){
        if(l%i==0 && __gcd(i,l/i)==1) return 0*printf("%lld %lld\n",min(g*i,g*l/i),max(g*i,g*l/i));
    }
}