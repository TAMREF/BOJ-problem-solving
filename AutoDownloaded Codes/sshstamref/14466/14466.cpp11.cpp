#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int mx=105;
int rep[mx*mx], sz[mx*mx], n, k, r, arr[mx*mx];
bool vis[mx*mx][4], vs[mx*mx];
int f(int x){return x==rep[x]?x:rep[x]=f(rep[x]);}
void c(int x, int y){
    x=f(x),y=f(y);
    if(x==y) return;
    rep[y]=x, sz[x]+=sz[y];
}
inline int code(int r, int c){
    return r*(n+2)+c;
}
int dr[4]={1,-1,0,0},dc[4]={0,0,1,-1};
int main(){
    queue<pii> Q;
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k>>r;
    for(int i=1;i<=n;i++){
        vis[code(n,i)][0]=vis[code(1,i)][1]=vis[code(i,n)][2]=vis[code(i,1)][3]=1;
        for(int j=1;j<=n;j++) rep[code(i,j)]=code(i,j);
    }
    for(int i=0,a,b,c,d;i<r;i++){
        cin>>a>>b>>c>>d;
        if(a==c){
            vis[code(a,b)][2|(b>d)]=vis[code(c,d)][2|(d>b)]=1;
        }else{
            vis[code(a,b)][a>c]=vis[code(c,d)][c>a]=1;
        }
    }
    for(int i=0,a,b;i<k;i++){
        cin>>a>>b;
        sz[code(a,b)]=1;
        vs[code(a,b)]=1;
        Q.emplace(a,b);
    }
    for(pii z;!Q.empty();){
        z=Q.front(); Q.pop();
        int cz=code(z.first,z.second), dz;
        for(int t=0;t<4;t++){
            if(!vis[cz][t]){
                c(cz,dz=code(z.first+dr[t],z.second+dc[t]));
                vis[cz][t]=1;
                if(!vs[dz]){
                    Q.emplace(z.first+dr[t],z.second+dc[t]);
                    vs[dz]=1;
                }
            }
        }
    }
    for(int p=0,i=1;i<=n;i++) for(int j=1;j<=n;j++) arr[p++]=f(code(i,j));
    sort(arr,arr+n*n);
    int u=unique(arr,arr+n*n)-arr, s2=0,s=0;
    for(int i=0;i<u;i++) s2+=sz[arr[i]]*sz[arr[i]], s+=sz[arr[i]];
    cout<<((s*s-s2)>>1)<<endl;
    return 0;
}