#include <bits/stdc++.h>
using namespace std;
inline long long tau(int x, int n){
    long long t=0;
    for(int i=1;i<=n;i++){
        if(1LL*i*i>=x){
            if(1LL*i*i==x) ++t;
            break;
        }
        if(x%i==0 && x/i<=n) t+=2;
    }
    return t;
}
int bs(int n,int k){
    int lo=1,mi,hi=k;
    long long S=0, T=0;
    for(;;){
        S=0;
        mi=(lo+hi)>>1;
        T=tau(mi,n);
        for(int i=1;i<=n;i++) S+=min(n,mi/i);
        if(S<k) lo=mi+1;
        else if(S-T>=k) hi=mi-1;
        else return !printf("%d\n",mi);
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    //for(n=5,k=1;k<=n*n;k++)
    {
        bs(n,k);
    }
}