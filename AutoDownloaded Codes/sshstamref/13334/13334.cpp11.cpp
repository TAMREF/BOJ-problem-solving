#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;
const int MX=100005;
pair<int,int> ho[MX];
int h[MX], cnt[MX];
int main(){
    int N,d; scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d%d",&ho[i].fst,&ho[i].snd);
        if(ho[i].fst>ho[i].snd) swap(ho[i].fst,ho[i].snd);
    } scanf("%d",&d);
    sort(ho,ho+N);
    for(int i=0;i<N;i++) h[i]=ho[i].fst;
    for(int i=0;i<N;i++){
        if(ho[i].snd-ho[i].fst<=d){
            ++cnt[lower_bound(h,h+N,ho[i].snd-d)-h];
            --cnt[upper_bound(h,h+N,ho[i].fst)-h];
        }
    } int ans=INT_MIN, pro=0;
    for(int i=0;i<N;i++){
        pro+=cnt[i]; ans=max(ans,pro);
    }
    printf("%d\n",ans);
    return 0;
}
