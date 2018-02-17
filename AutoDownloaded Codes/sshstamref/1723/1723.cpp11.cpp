#include <bits/stdc++.h>
using namespace std;
int n,k;
double r[20010];
void input(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%lf",&r[i]);
    sort(r,r+n);
    copy(r,r+n,r+n);
    for(int i=n;i<n+n;i++) r[i]+=360.0;
}
int pro(){
    int ans=n;
    for(int i=0;i<n;i++){
        int mx=0,mn=n;
        for(int j=1,pos=i,tpo;j<=k;j++){
            //printf("i=%d, j=%d, pos=%d\n",i,j,pos);
            tpo=lower_bound(r,r+n+n,r[i]+360.0/(double)k*(double)j)-r;
            mn=min(mn,tpo-pos), mx=max(mx,tpo-pos), pos=tpo;
        }
        //printf("%d %d %d\n",i,mx,mn);
        ans=min(ans,mx-mn);
    }
    return ans;
}
int main(){
    input();
    cout<<pro()<<endl;
}