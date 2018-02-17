#include <bits/stdc++.h>
using namespace std;

typedef long double lf;
typedef long long ll;

const int mx = 1005;
const lf eps = 0.000001L;

int t;

int w, n;

struct circle{
    int x,y,r;
} tam[mx];

ll distsq(circle c, circle d){
    return (ll)(c.x-d.x)*(c.x-d.x) + (ll)(c.y-d.y)*(c.y-d.y);
}
lf dist(circle c, circle d){
    return sqrt((ll)(c.x-d.x)*(c.x-d.x) + (ll)(c.y-d.y)*(c.y-d.y));
}

namespace fio {
	const int BSIZE = 1<<24;
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
	int readSignedInt(){
        char c = readChar();
        while(c < '0' && c != '-'){
            c = readChar();
        }
        int ret = 0, sgn = 1;
        if(c == '-'){
            sgn = -1;
            c = readChar();
        }
        while(c >= '0'){
            ret = ret * 10 + c - '0';
            c = readChar();
        }
        return sgn * ret;
	}
}

namespace dj{
    int rep[mx];
    int sz[mx];
    int f(int x){
        return x==rep[x]?x:rep[x] = f(rep[x]);
    }
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
    void init(int n){
        iota(rep,rep+n,0);
        fill(sz,sz+n,1);
    }
}

void input(){
    using namespace fio;
    w = readInt();
    n = readInt();
    for(int i=1;i<=n;i++){
        tam[i].x = readInt();
        tam[i].y = readSignedInt();
        tam[i].r = readInt();
    }
}

bool uf(lf rho){
    dj::init(n+2);
    using namespace dj;
    for(int i=1;i<=n;i++){
        if(2.L * rho + tam[i].r >= tam[i].x){
            c(0,i);
        }
        if(2.L * rho + tam[i].r + tam[i].x >= w){
            c(i,n+1);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(distsq(tam[i],tam[j]) < (2.L * rho + tam[i].r + tam[j].r)*(2.L * rho + tam[i].r +tam[j].r)){
                c(i,j);
            }
        }
    }
    return f(0) != f(n+1);
}
bool uf0(){
    dj::init(n+2);
    using namespace dj;
    for(int i=1;i<=n;i++){
        if(tam[i].r >= tam[i].x){
            c(0,i);
        }
        if(tam[i].r + tam[i].x >= w){
            c(i,n+1);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(distsq(tam[i],tam[j]) <= (ll)(tam[i].r + tam[j].r)*(tam[i].r + tam[j].r)){
                c(i,j);
            }
        }
    }
    return f(0) != f(n+1);
}

int main(){   
    using namespace fio;
    t = readInt();
    for(int f=0;f<t;f++){
        input();
        if(!uf0()){
            puts("0");
            continue;
        }
        lf lo = 0, mi, hi = 0.5L * w;
        while(hi - lo > eps){
            mi = 0.5L * (lo + hi);
            if(uf(mi)){
                lo = mi;
            }else{
                hi = mi;
            }
        }
        printf("%.8Lf\n",mi);
    }
}
