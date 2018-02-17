#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
const ll mod[2]={1000000007,1610612741};
ll pow1500[2][26]={{1},{1}};
char A[1505], B[1505];
int N,M;
set<pair<ll,ll>> S;
void init(){
    for(int i=1;i<26;i++) for(int b=0;b<2;b++) pow1500[b][i]=(pow1500[b][i-1]*1500)%mod[b];
    fgets(A,1502,stdin); N=strlen(A); A[--N]=0;
    fgets(B,1502,stdin); M=strlen(B); B[--M]=0;
    for(int i=0;i<N;i++) A[i]-='a';
    for(int i=0;i<M;i++) B[i]-='a';
}
bool pro(int x){
    S.clear();
    ll H[2]={0,0};
    for(int i=0;i<x;i++)for(int b=0;b<2;b++) H[b]=(H[b]+pow1500[b][A[i]])%mod[b];
    S.insert(mp(H[0],H[1]));
    for(int i=x;i<N;i++){
        for(int b=0;b<2;b++)
            H[b]=(((H[b]+pow1500[b][A[i]])%mod[b]-pow1500[b][A[i-x]])%mod[b]+mod[b])%mod[b];
        S.insert(mp(H[0],H[1]));
    }
    H[0]=H[1]=0;
    for(int i=0;i<x;i++) for(int b=0;b<2;b++) H[b]=(H[b]+pow1500[b][B[i]])%mod[b];
    if(S.find(mp(H[0],H[1]))!=S.end()) return true;
    for(int i=x;i<M;i++){
        for(int b=0;b<2;b++)
            H[b]=(((H[b]+pow1500[b][B[i]])%mod[b]-pow1500[b][B[i-x]])%mod[b]+mod[b])%mod[b];
        if(S.find(mp(H[0],H[1]))!=S.end()) return true;
    }
    return false;
}
int main(){
    init();
    int ans=0, x=min(N,M);
    for(int i=1;i<=x;i++) if(pro(i)) ans=max(ans,i);
    printf("%d\n",ans);
}