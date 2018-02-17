#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;
const int MX=100005;
typedef pair<int,int> pii;
inline int sq(int k){return k*k;}
inline int d(pii u, pii v){return sq(u.fst-v.fst)+sq(u.snd-v.snd);}
pii tam[MX], ding[MX], cpy[MX];
bool cmp(pii u, pii v){return u.snd<v.snd;}
int cp(int s, int e){
    if(s==e) return 1e9;
    vector<pii> can;
    int m=(s+e)>>1, ds=min(cp(s,m),cp(m+1,e));
    merge(ding+s,ding+m+1,ding+m+1,ding+e+1,cpy+s,cmp);
    copy(cpy+s,cpy+e+1,ding+s);
    for(int i=s;i<=e;i++)
        if(sq(tam[m].fst-ding[i].fst)<ds) can.push_back(ding[i]);
    for(int i=0,C=can.size();i<C;i++){
        for(int j=i+1;j<C&&sq(can[j].snd-can[i].snd)<ds;j++) ds=min(ds,d(can[i],can[j]));
    }
    return ds;
}
int main(){
    int N; scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d %d",&tam[i].fst,&tam[i].snd);
    sort(tam,tam+N);
    copy(tam,tam+N,ding);
    printf("%d\n",cp(0,N-1));
    return 0;
}
