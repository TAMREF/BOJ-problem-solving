#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double lf;
typedef tuple<double,int,int> edge;

const int mv = 1005;

namespace fio {
	const int BSIZE = 524288;
	char buffer[BSIZE];
	char *p = buffer + BSIZE;
	inline char readChar() {
		if (p == buffer + BSIZE) {
			fread(buffer, 1, BSIZE, stdin);
			p = buffer;
		}
		return *p++;
	}
	int readInt() {
		char c = readChar();
		while (c < '0') {
			c = readChar();
		}
		int ret = 0;
		while (c >= '0') {
			ret = ret * 10 + c - '0';
			c = readChar();
		}
		return ret;
	}
}

struct pt{
    ll x, y;
} tam[mv];

lf di(pt &u, pt &v){
    return sqrt((u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y));
}

int n, m;
int cn;

lf dist[mv][mv];
int rep[mv];
vector<edge> E;

int f(int x){
    return x==rep[x]?x:rep[x]=f(rep[x]);
}

int c(int x, int y){
    x = f(x), y = f(y);
    rep[y] = x;
    return x==y?0:1;
}

void init(){
    n = fio::readInt(); m = fio::readInt();
    iota(rep,rep+n,0);
    
    for(int i=0;i<n;i++){
        tam[i].x = fio::readInt();
        tam[i].y = fio::readInt();
    }
    for(int i=0,a,b;i<m;i++){
        a = fio::readInt(); b = fio::readInt();
        c(a-1,b-1);
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j] = 1e16;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(f(i) != f(j)){
                dist[f(i)][f(j)] = min(dist[f(i)][f(j)], di(tam[i], tam[j]));
            }
        }
    }
}

bool vis[mv][mv];

lf kruskal(){
    lf tot = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(f(i) != f(j) && !vis[f(i)][f(j)] && !vis[f(j)][f(i)]){
                vis[f(i)][f(j)] = 1;
                E.push_back(make_tuple(dist[f(i)][f(j)],f(i),f(j)));
            }
        }
    }
    
    sort(E.begin(),E.end());
    lf co;
    int u, v;
    for(edge &e : E){
        tie(co,u,v) = e;
        //printf("%.2f %d %d\n",co,u+1,v+1);
        if(c(u,v)){
            //puts("is accpeted");
            tot += co;
        }
    }
    
    return tot;
}

int main(){
    E.reserve(1000 * 999 / 2);
    init();
    printf("%.2f\n",kruskal());
}