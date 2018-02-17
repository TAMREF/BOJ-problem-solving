#include <bits/stdc++.h>
using namespace std;
int N,M,P[300005];
inline int ce(int n, int m){
    return n/m+(n%m>0);
}
inline bool pro(int x){
    long long u=0;
    for(int i=0;i<M;i++){
        u+=ce(P[i],x);
        if(u>N) return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<M;i++) cin>>P[i];
    int lo=1,mi,hi=*max_element(P,P+M);
    while(lo<hi){
        mi=(lo+hi)>>1;
        if(pro(mi)) hi=mi;
        else lo=mi+1;
    }
    cout<<hi<<endl;
}