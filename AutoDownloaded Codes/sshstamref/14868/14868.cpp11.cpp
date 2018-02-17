#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int mx = 2050;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; //NESW
const int inf = 1e8;

int rep[mx * mx], lev[mx][mx], rnk[mx * mx];

int n, k;

queue<pii> Q;

int f(int x){
    return x==rep[x]?x:rep[x]=f(rep[x]);
}

void input(){
    cin >> n >> k;
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) lev[i][j] = inf;

    for(int i=0,x,y;i<k;i++){
        cin >> x >> y;
        lev[x][y] = 0;
        rep[x * n + y] = x * n + y;
        Q.emplace(x,y);
    }
}

bool ok(int x, int y){
    return x > 0 && x <= n && y > 0 && y <= n;
}

void BFS(){
    int ti = 0, comp = k;
    for(int x,y,nx,ny,u,v;;++ti){
        //printf("time : %d\n",ti);
        while(!Q.empty()){
            x = Q.front().first; y = Q.front().second;
            //printf("working on (%d,%d)\n",x,y);
            if(lev[x][y] != ti) break;
            Q.pop();
            if(!ok(x,y)) continue;
            for(int d = 0;d < 4;d++){
                nx = x + dx[d], ny = y + dy[d];
                if(!ok(nx,ny)) continue;
                if(lev[nx][ny] == inf){
                    lev[nx][ny] = ti + 1;
                    rep[nx * n + ny] = f(x * n + y);
                    Q.emplace(nx,ny);
                }else if(lev[nx][ny] <= ti){
                    u = f(nx * n + ny); v = f(x * n + y);
                    if(rnk[u] > rnk[v]) swap(u,v);
                    if(u != v){
                        rep[v] = u;
                        if(rnk[u] == rnk[v]) rnk[u] = rnk[v] + 1;
                        --comp;
                    }
                }
            }
            if(comp == 1) break;
        }
        //printf("# of comp : %d\n",comp);
        if(comp == 1) break;
    }
    cout << ti << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    BFS();
}
