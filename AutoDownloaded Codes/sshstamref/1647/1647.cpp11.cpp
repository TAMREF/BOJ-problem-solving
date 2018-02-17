#include <bits/stdc++.h>
using namespace std;

const int mv = 2e5 + 5, me = 1e6 + 5;

struct edge{
    int v1, v2, c;
    int op(int x){
        return v1 + v2 - x;
    }
} E[me];

int n, m;

int rep[mv], sz[mv];

int f(int x){return x==rep[x]?x:rep[x]=f(rep[x]);}
int c(int x, int y){
    x = f(x), y = f(y);
    if(sz[x] < sz[y]) swap(x,y);
    if(x!=y){
        rep[y] = x;
        sz[x] += sz[y];
        return 1;
    }
    return 0;
}

void input(){
    cin>>n>>m;
    iota(rep,rep+n,0);
    fill(sz,sz+n,1);
    for(int i=0;i<m;i++){
        cin>>E[i].v1>>E[i].v2>>E[i].c;
        --E[i].v1; --E[i].v2;
    }
    sort(E,E+m,[](edge u, edge v){return u.c<v.c;});
}

int kruskal(){
    int maxe = 0, tot = 0;
    for(int i=0;i<m;i++){
        if(c(E[i].v1,E[i].v2)){
            tot += E[i].c;
            maxe = max(maxe, E[i].c);
        }
    }
    return tot - maxe;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    cout << kruskal() << endl;
}