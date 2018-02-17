#include <bits/stdc++.h>
using namespace std;
const int mv = 100005;
const int me = 200005;

int n, m;

int dt[mv], clk;
int deg[mv];
//int dt_bcc[mv], clk_bcc;

struct edge{
    int idx, v1, v2;
} E[me];

vector<int> G[mv];
//vector<int> G_bcc[mv];

vector<int> cute;
vector<int> deg1;
//vector<int> cute_bcc;

int rep[mv];

int f(int x){
    return x==rep[x]?x:rep[x] = f(rep[x]);
}

void c(int x, int y){
    x = f(x), y = f(y);
    if(x!=y){
        rep[y] = x;
    }
}

int dfs(int x, int Eidx){
    dt[x] = ++clk;
    int ret = dt[x], tmp, u;
    for(int& ei : G[x]){
        u = E[ei].v1 + E[ei].v2 - x;
        if(!dt[ u ]){
            tmp = dfs( u , ei );
            if( tmp > dt[x] ){
                cute.push_back(ei);
            }else{
                c(x, u);
            }

            ret = min(ret,tmp);
        }else if(ei != Eidx){
            ret = min(ret, dt[u]);
            c(x, u);
        }
    }
    return ret;
}

void input(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        E[i].idx = i;
        cin>>E[i].v1>>E[i].v2;
        --E[i].v1; --E[i].v2;
        G[ E[i].v1 ].push_back(i);
        G[ E[i].v2 ].push_back(i);
    }
    iota(rep,rep+n,0);
}

void connect(){
    for(int &ei : cute){
        ++deg[ f(E[ei].v1) ];
        ++deg[ f(E[ei].v2) ];
    }
    for(int i=0;i<n;i++){
        if(0<deg[i] && deg[i]<2){
            deg1.push_back(i);
        }
    }

    int c = deg1.size();
    cout << (c + 1)/2 << '\n';
    for(int i=0;i<c;i+=2){
        cout<< deg1[i]+1 << ' ' << deg1[(i+1)%c]+1 << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    dfs(0,-1);
    connect();
}
