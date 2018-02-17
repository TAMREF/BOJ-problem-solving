#include <bits/stdc++.h>
using namespace std;
int primes[10005]={2}, np=1, chk[10005];
void bprime(){
    for(int i=3;i<=10000;i+=2){
        if(!chk[i]){
            primes[np++]=i;
            for(int j=i*i;j<=10000;j+=i) chk[j]=1;
        }
    }
}
int nfac(int x){
    if(x<3) return 1;
    int cnt=0;
    for(int t=0;t<np;t++){
        if(x==1) break;
        if(x%primes[t]==0){
            ++cnt;
            for(;x%primes[t]==0;x/=primes[t]);
        }
    }
    return x>1?cnt+1:cnt;
}
int main(){
    bprime();
    int T;
    for(int n=scanf("%d",&T);T--;){
        scanf("%d",&n);
        printf("%d\n",1<<(nfac(n)-1));
    }
}