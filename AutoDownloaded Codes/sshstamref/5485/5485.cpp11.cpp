#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
void input(){
    cin>>n;
}
ll pro(){
    ll now=0, lb=LLONG_MIN, ub=LLONG_MAX, M;
    for(int i=0;i<n;i++){
        cin>>M;
        if(i&1){
            lb=max(lb,now-M);
            now-=(M<<1);
        }else{
            ub=min(ub,now+M);
            now+=(M<<1);
        }
    }
    return ub<lb?0:ub-lb+1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    cout<<pro()<<endl;
    return 0;
}