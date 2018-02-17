#include <bits/stdc++.h>
#define vc first
#define vp second
#define all(X) X.begin(),X.end()
using namespace std;
typedef pair<int,int> pii;
const int mx=1005, inf=1e8;
int s,e;
int R,C;
int D[mx*mx];
vector<int> rs[mx], cs[mx], rrs[mx], rcs[mx];
char buf[mx][mx+8];
void input(){
    scanf("%d %d\n",&R,&C);
    for(int i=1;i<=R;i++) scanf("%s",buf[i]+1);
    for(int i=0;i<=C+1;i++) buf[0][i]=buf[R+1][i]='#';
    for(int j=0;j<=R+1;j++) buf[j][0]=buf[j][C+1]='#';
    for(int i=0;i<R+2;i++){
        for(int j=0;j<C+2;j++){
            if(buf[i][j]=='S') s=i*(C+2)+j;
            else if(buf[i][j]=='C') e=i*(C+2)+j;
            else if(buf[i][j]=='#'){
                rs[i].push_back(j);
                cs[j].push_back(i);
            }
        }
    }
    for(int i=0;i<R+2;i++){
        rrs[i]=rs[i];
        reverse(all(rrs[i]));
    }
    for(int j=0;j<C+2;j++){
        rcs[j]=cs[j];
        reverse(all(rcs[j]));
    }
    fill(D,D+(R+2)*(C+2),inf);
    R+=2, C+=2;
}
void dijk(){
    priority_queue<pii,vector<pii>,greater<pii>> q;
    int dr[4]={1,-1,C,-C};
    q.push(pii(D[s]=0,s));
    while(!q.empty()){
        pii u = q.top(); q.pop();
        int flag=0,tr=u.vp/C,tc=u.vp%C;
        if(buf[tr][tc]=='#' || D[u.vp]<u.vc) continue;
        //printf("(%d,%d) arrived\n",tr,tc);
        for(int t=0;t<4;t++){
            int np=u.vp+dr[t];
            if(buf[np/C][np%C]=='#') flag=1;
            else{
                if(D[np]>u.vc+1) q.push(pii(D[np]=u.vc+1,np));
            }
        }
        int nr[4]={tr,tr,*lower_bound(all(cs[tc]),tr)-1,*lower_bound(all(rcs[tc]),tr,greater<int>())+1},
            nc[4]={*lower_bound(all(rs[tr]),tc)-1,*lower_bound(all(rrs[tr]),tc,greater<int>())+1,tc,tc},
            np,
            cost[4];
        if(flag) for(int t=0;t<4;t++) cost[t]=1;
        else{
            for(int t=0;t<4;t++){
                cost[t]=inf;
                for(int u=0;u<4;u++)
                    cost[t]=min(cost[t],abs(tr-nr[u])+abs(tc-nc[u])+1);
            }
        }
        for(int t=0;t<4;t++){
            np=nr[t]*C+nc[t];
            if(D[np]>u.vc+cost[t]) q.push(pii(D[np]=u.vc+cost[t],np));
        }
    }
}
int main(){
    input();
    dijk();
    printf("%d\n",D[e]);
}