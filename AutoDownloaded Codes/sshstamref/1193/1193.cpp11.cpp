#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,p,u,v;
    scanf("%d",&n);
    p=(int)((1+sqrt(1+8*n))/2);
    u=n-(p*(p-1)/2), v=p+1-u;
    if(u==0) ++u, v-=2;
    if(p&1) printf("%d/%d\n",v,u);
    else printf("%d/%d\n",u,v);
}