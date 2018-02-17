#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
set<pii> tam;
int N;
void input(){
    scanf("%d",&N);
    pii p;
    for(int i=0;i<N;i++){
        scanf("%lld%lld",&p.fst,&p.snd);
        auto l = tam.lower_bound(p);
        if(tam.find(p)!=tam.end() || l!=tam.end() && p.snd<l->snd) continue;
        tam.insert(p);
    }
}
inline ll f(pii u, ll k){
    return u.fst*k+u.snd;
}
ll CHT(){
    vector<pii> ding(0), ch(tam.size()+3,{-1,-1});
    ll ans;
    int top=1, ptr=0;
    pii dp, g, h;
    ding.assign(tam.begin(),tam.end());
    for(int i=1;i<ding.size();i++){
        int j=lower_bound(ding.begin(),ding.begin()+i,ding[i],[](pii u, pii v){return u.snd>=v.snd;})-ding.begin();
        if(j<i){
            ding.erase(ding.begin()+j,ding.begin()+i);
            i=j;
        }
        if(ding.size()==1) return ding[0].fst*ding[0].snd;
    }
    ding.push_back({-1,-1});
    ch[0]={ding[0].snd,0};
    for(int i=0,S=ding.size();i<S-1;i++){
        while(ptr<top-1 && f(ch[ptr],ding[i].fst)>=f(ch[ptr+1],ding[i].fst)) ++ptr;
        ans = f(ch[ptr],ding[i].fst);
        dp={ding[i+1].snd,ans};
        while(top>1){
            g=ch[top-1], h=ch[top-2];
            if((dp.snd-h.snd)*(h.fst-g.fst)<=(h.fst-dp.fst)*(g.snd-h.snd)){
                if(ptr==top) --ptr;
                --top;
            } else break;
        }
        ch[top++]=dp;
    }
    return ans;
}
int main(){
    input();
    printf("%lld\n",CHT());
}
