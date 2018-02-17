#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100005], b[100005], m[100005], n[100005];
ll cross(int s, int e){
    if(s==e) return 0;
    int m=(s+e)>>1;
    ll res=cross(s,m)+cross(m+1,e);
    int i=s,j=m+1, c=s;
    while(i<=m&&j<=e){
        if(b[i]>b[j]){
            n[c++]=b[j++];
        } else{
            res+=j-m-1;
            n[c++]=b[i++];
        }
    }
    if(j>e) res+=(ll)(e-m)*(m-i+1);
    copy(b+i,b+m+1,n+c);
    copy(b+j,b+e+1,n+c);
    copy(n+s,n+e+1,b+s);
    return res;
}
int main(){
    for(int T, N=scanf("%d",&T);T--;){
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            scanf("%d",&a[i]);
            m[a[i]]=i;
        }
        for(int i=0;i<N;i++){
            scanf("%d",&b[i]);
            b[i]=m[b[i]];
        }
        printf("%lld\n",cross(0,N-1));
    }
}
