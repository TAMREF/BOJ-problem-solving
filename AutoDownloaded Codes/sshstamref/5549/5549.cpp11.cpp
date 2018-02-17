#include <bits/stdc++.h>
using namespace std;
int JOI[3][1005][1005];
int a[255];
char buf[3000];
inline int psum(int p,int sr,int sc,int er, int ec){
    return JOI[p][er][ec]-JOI[p][er][sc-1]-JOI[p][sr-1][ec]+JOI[p][sr-1][sc-1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    a['J']=0, a['O']=1, a['I']=2;
    int n,m,k; cin>>n>>m>>k;
    char x;
    for(int i=1;i<=n;i++){
        //cin>>x;
        //cout<<(int)x<<", is it newline?"<<endl;
        //cout<<i<<" th : ";
        for(int j=1;j<=m;j++){
            cin>>x;
            //cout<<x;
            ++JOI[a[x]][i][j];
            for(int p=0;p<3;p++) JOI[p][i][j]+=JOI[p][i-1][j]+JOI[p][i][j-1]-JOI[p][i-1][j-1];
        }
        //cout<<endl;
    }
    for(int a,b,c,d;k--;){
        cin>>a>>b>>c>>d;
        cout<<psum(0,a,b,c,d)<<' '<<psum(1,a,b,c,d)<<' '<<psum(2,a,b,c,d)<<'\n';
    }
}