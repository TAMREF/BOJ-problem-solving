#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef pair<int,int> ii;
typedef pair<short,short> ss;
const int mx=1505;
ii H[mx][4], V[mx][4];
ii sh[mx*mx];
int ts;
int th[mx], tv[mx];
int h[mx][mx],dp[mx][mx];
ss v[mx*mx];
int n,nr,nc;
void input(){
    short i,j;
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>nr>>nc;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>h[i][j];
            v[n*(i-1)+j-1]=ss(i,j);
        }
    }
    sort(v,v+n*n,[](ss p,ss q)->bool{
        return h[p.va][p.vb]>h[q.va][q.vb];
    });
}
void do_dp(){
    int r,c,nowh=-1,dpmx,j;
    ii hi, vi;
    for(int i=0;i<n*n;i++){
        r=v[i].va, c=v[i].vb;
        dpmx=0;
        if(h[r][c]!=nowh){
            nowh=h[r][c];
            for(j=0;j<ts;j++){
                hi=ii(dp[sh[j].va][sh[j].vb],sh[j].vb);
                vi=ii(dp[sh[j].va][sh[j].vb],sh[j].va);
                if(th[sh[j].va]==4) *min_element(H[sh[j].va],H[sh[j].va]+4)=hi;
                else H[sh[j].va][th[sh[j].va]++]=hi;
                if(tv[sh[j].vb]==4) *min_element(V[sh[j].vb],V[sh[j].vb]+4)=vi;
                else V[sh[j].vb][tv[sh[j].vb]++]=vi;
            }
            ts=0;
        }
        for(j=0;j<th[r-1];j++){
            if(abs(H[r-1][j].vb-c)>1)
                dpmx=max(dpmx,H[r-1][j].va);
        }
        for(j=0;j<th[r+1];j++){
            if(abs(H[r+1][j].vb-c)>1)
                dpmx=max(dpmx,H[r+1][j].va);
        }
        for(j=0;j<tv[c-1];j++){
            if(abs(V[c-1][j].vb-r)>1)
                dpmx=max(dpmx,V[c-1][j].va);
        }
        for(j=0;j<tv[c+1];j++){
            if(abs(V[c+1][j].vb-r)>1)
                dpmx=max(dpmx,V[c+1][j].va);
        }
        dp[r][c]=++dpmx;
        sh[ts++]=ii(r,c);
    }
}
int main(){
    input();
    do_dp();
    printf("%d\n",dp[nr][nc]);
}