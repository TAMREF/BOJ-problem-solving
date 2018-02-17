#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef pair<int,int> ii;
ii operator+ (ii u, ii v){return ii(u.va+v.va,u.vb+v.vb);}
ii operator- (ii u, ii v){return ii(u.va-v.va,u.vb-v.vb);}
double norm(ii x){return sqrt((double)x.va*x.va+(double)x.vb*x.vb);}
int ix[10];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T, n;
    ii tam[20];
    for(cin>>T;T--;){
        cin>>n;
        ii tot(0,0);
        double ans=1e18;
        for(int i=0;i<n;i++) cin>>tam[i].va>>tam[i].vb;
        for(int i=0;i<(1<<n);i++){
            if(__builtin_popcount(i)!=(n>>1)) continue;
            tot=ii(0,0);
            for(int j=0;j<n;j++) tot=(i&1<<j)?tot+tam[j]:tot-tam[j];
            ans=min(ans,norm(tot));
        }
        printf("%.6f\n",ans);
    }
}