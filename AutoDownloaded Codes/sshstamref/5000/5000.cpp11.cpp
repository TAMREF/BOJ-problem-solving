#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005],r[100005];
struct BIT{
    int f[100005];
    int sum(int i){
        int s=0;
        for(;i;i-=i&-i) s+=f[i];
        return s;
    }
    void inc(int i){
        for(;i<=n;i+=i&-i) ++f[i];
    }
} w;
int main(){
    int even=0;
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1,x;i<=n;i++) {
        cin>>x;
        r[x]=i;
    }
    for(int i=1,y;i<=n;i++){
        cin>>y;
        a[r[y]]=i;
    }
    for(int i=1;i<=n;i++){
        even ^= (i-1-w.sum(a[i]))&1;
        w.inc(a[i]);
    }
    cout<<(even?"Impossible":"Possible")<<endl;
}