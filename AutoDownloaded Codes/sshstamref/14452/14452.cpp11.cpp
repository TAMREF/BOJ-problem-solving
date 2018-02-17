#include <bits/stdc++.h>
using namespace std;
const int mx=10005;
int dur[mx], n, t;
bool pro(int k){
    priority_queue<int,vector<int>,greater<int>> pQ;
    for(int i=0;i<k;i++) pQ.push(dur[i]);
    for(int i=k;i<n;i++){
        int clk=pQ.top(); pQ.pop();
        if(clk+dur[i]>t) return false;
        pQ.push(clk+dur[i]);
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>t;
    for(int i=0;i<n;i++) cin>>dur[i];
    int lo=1,mi,hi=n;
    for(;lo<hi;){
        mi=(lo+hi)>>1;
        if(pro(mi)) hi=mi;
        else lo=mi+1;
    }
    cout<<lo<<endl;
}