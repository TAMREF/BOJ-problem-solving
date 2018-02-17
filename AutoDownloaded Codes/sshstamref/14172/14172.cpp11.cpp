#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
inline ll sq(int x){return 1LL*x*x;}
inline ll dist(ii u, ii v){return sq(u.first-v.first)+sq(u.second-v.second);}
ii c[202];
int p[202], n;
int reach[202][202];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>c[i].first>>c[i].second>>p[i];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(dist(c[i],c[j])<sq(p[i])) reach[i][j]=1;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(reach[i][k] && reach[k][j]) reach[i][j]=1;
            }
        }
    }
    int mr=0;
    //for(int i=0;i<n;i++) for(int j=0;j<n;j++) cout<<reach[i][j]<<" \n"[j==n-1];
    for(int i=0;i<n;i++) mr=max(mr,(int)count(reach[i],reach[i]+n,1));
    cout<<mr<<endl;
    return 0;
}