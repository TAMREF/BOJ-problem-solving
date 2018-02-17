#include <bits/stdc++.h>
using namespace std;
const int mx = 100005;
int Q;
int A[mx], B[mx], C[mx], P[mx];

struct RangeBIT{
    int a[mx], n;
    void update(int s, int e){
        for( ; s<=n ; s += (s&-s)) ++a[s];
        for(++e; e<=n ; e += (e&-e)) --a[e];
    }
    int sum(int x){
        int S = 0;
        for(;x;x -= (x&-x)) S += a[x];
        return S;
    }
} F;

void input(){
    cin>>F.n>>Q;
    for(int i=0;i<Q;i++) cin>>P[i];
    for(int i=1;i<F.n;i++) cin>>A[i]>>B[i]>>C[i];
}

void query(){
    for(int i=1;i<Q;i++){
        if(P[i] > P[i-1])
            F.update(P[i-1],P[i]-1);
        else
            F.update(P[i],P[i-1]-1);
    }
}

void output(){
    long long ans = 0;
    for(int i=1;i<F.n;i++){
        long long si = F.sum(i);
        //cout<<i<<" : "<<si<<" times, cost = "<<min(si*A[i],si*B[i]+C[i])<<endl;
        ans += min(si*A[i],si*B[i]+C[i]);
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    query();
    output();
}
