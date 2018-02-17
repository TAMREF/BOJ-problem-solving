#include <bits/stdc++.h>
using namespace std;
int d[65536],n,w[16][16],bm,P;
char x;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>w[i][j];
    for(int i=0;i<(1<<n);i++) d[i]=INT_MAX;
    for(int i=0;i<n;i++){
        cin>>x;
        bm|=(int)(x=='Y')<<i;
    }
    cin>>P;
    d[bm]=0;
    for(int g=0,h;g<(1<<n);g++){
        if(d[g]==INT_MAX) continue;
        for(int i=0;i<n;i++){
            if((g&1<<i)==0) continue;
            for(int j=0;j<n;j++){
                if(g&1<<j) continue;
                h=g|1<<j;
                d[h]=min(d[g]+w[i][j],d[h]);
            }
        }
    }
    int F=INT_MAX;
    for(int g=0;g<(1<<n);g++) if(__builtin_popcount(g)>=P) F=min(F,d[g]);
    cout<<(F==INT_MAX?-1:F)<<endl;
    return 0;
}