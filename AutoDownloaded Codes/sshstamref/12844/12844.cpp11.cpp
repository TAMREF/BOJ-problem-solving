#include <bits/stdc++.h>
using namespace std;
const int maxn=500005;
struct BIT{
    int n, ft[maxn];
} X,Y;
void update(BIT& f, int p, int v){
    for(;p<=f.n;p += (p&-p)) f.ft[p]^=v;
}
void update(int a, int b, int v){
    update(X,a,v);
    update(X,b+1,v);
    if(a%2==0) update(Y,a,v);
    if(b%2==1) update(Y,b+1,v);
}
int query(BIT &f, int b){
    int sum=0;
    for(;b;b-=b&-b) sum^=f.ft[b];
    return sum;
}
int query(int b){
    return (b&1?query(X,b):0)^query(Y,b);
}
int query(int a, int b){
    return query(b)^query(a-1);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n; X.n=Y.n=n;
    for(int i=1,x;i<=n;i++){
        cin>>x;
        update(i,i,x);
    }
    cin>>q;
    for(int t,a,b,c;q--;){
        cin>>t>>a>>b;
        if(a>b) swap(a,b);
        if(t==1){
            cin>>c;
            update(a+1,b+1,c);
        }else{
            cout<<query(a+1,b+1)<<'\n';
        }
    }
    return 0;
}