#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx=100005, o=131072;
int n;

ll psum[mx];

struct Indextree{
    ll O[o+o];
    void init(){
        for(int x=o;x>1;x>>=1){
            for(int y=x;y<x+x;y+=2){
                O[y>>1]=min(O[y],O[y+1]);
            }
        }
    }
    ll getmin(int s, int e){
        s+=o, e+=o;
        ll ans = min(O[s],O[e]);
        while(s<=e){
            ans = min({ans,O[s],O[e]});
            (++s)>>=1, (--e)>>=1;
        }
        return ans;
    }
} I;

void init(){
    cin>>n;
    I.O[o] = -1;
    for(int i=1;i<=n;i++){
        cin>>I.O[o+i];
        psum[i] = psum[i-1] + I.O[o+i];
    }
    I.O[o+n+1] = -1;
    I.init();
}

ll pro(int p){
    int lo=p,mi,hi=n,hans;
    while(lo<hi){
        mi=(lo+hi+1)>>1;
        if(I.getmin(lo,mi)<I.O[o+p]) hi=mi-1;
        else lo=mi;
    }
    hans = lo;
    lo=1,hi=p;
    while(lo<hi){
        mi=(lo+hi)>>1;
        if(I.getmin(mi,hi)<I.O[o+p]) lo=mi+1;
        else hi=mi;
    }
    return (psum[hans]-psum[hi-1])*I.O[o+p];
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    ll ans=-1;
    for(int i=1;i<=n;i++) ans = max(ans, pro(i));
    cout<<ans<<endl;
    return 0;
}