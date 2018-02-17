#include <bits/stdc++.h>
using namespace std;
int broken[100005];
int n,k,b;
inline bool pro(int f){
    for(int i=f;i<=b;i++){
        if(broken[i+1]-broken[i-f]>k) return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k>>b;
    for(int i=1;i<=b;i++) cin>>broken[i];
    broken[b+1]=n+1;
    sort(broken+1,broken+b+1);
    //for(int i=1;i<=b;i++) cout<<broken[i]<<" \n"[i==b];
    int lo=0,hi=b,mi;
    for(;lo<hi;){
        mi=(lo+hi)>>1;
        //cout<<lo<<' '<<mi<<' '<<hi<<endl;
        if(pro(mi)) hi=mi;
        else lo=mi+1;
    }
    cout<<lo<<endl;
}