#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef int (*func)(int,int);
const int nh = 2, MX=222222;
unordered_set<int> ding[nh];
ll mod[nh]={1610612741,1000000207};
int N, i, j, k;
char buf[MX];
struct ht{
    int md;
    ll p26[MX];
    ll H[MX];
    inline ll m(ll x, ll y){return (x*y)%md;}
    inline ll p(ll x, ll y){return (x+y)%md;}
    inline ll s(ll x, ll y){return ((x-y)%md+md)%md;}
    ht(){}
    void mk(int _md){
        md=_md;
        p26[0]=1;
        for(i=1;i<=N;i++) p26[i]=m(p26[i-1],26);
    }
    ll build_hash(int st, int len){
        if(st==0){
            H[0]=0;
            for(i=0;i<len;i++) H[0]=p(m(H[0],26),buf[i]);
            return H[0];
        }
        return H[st]=p(m(s(H[st-1],m(p26[len-1],(ll)buf[st-1])),26),buf[st+len-1]);
    }
    void debug(){
        for(i=0;i<N;i++) printf("%lld ",H[i]); puts("");
    }
};
ht tam[nh];
void input(){
    scanf("%d\n",&N);
    scanf("%s",buf);
    for(i=0;i<N;i++) buf[i]-='a';
    for(k=0;k<nh;k++) tam[k].mk(mod[k]);
}
bool sch(int L){
    for(k=0;k<nh;k++)
        ding[k].clear();
    bool ch;
    for(j=0;j+L<=N;j++){
        ch=true;
        for(k=0;k<nh;k++){
            tam[k].build_hash(j,L);
            ch = ch && ding[k].find(tam[k].H[j])!=ding[k].end();
            ding[k].insert(tam[k].H[j]);
        }
        if(ch) return true;
    }
    return false;
}
void para(){
    int low=1, mid, ans=0, high=N;
    while(low<=high){
        mid = (low+high)>>1;
        if(sch(mid)) low = (ans=mid)+1;
        else high=mid-1;
    }
    printf("%d\n",ans);
}
int main(){
    input();
    para();
    return 0;
}