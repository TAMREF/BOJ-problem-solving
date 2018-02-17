#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int mv = 1005, me = 500005;
const int inf = 1e9;

struct edge{
    int u, v, c;
    int op(int x){
        return u+v-x;
    }
} E[me];

vector<int> G[mv];
int n, m;
int bck[mv], dist[mv];
priority_queue<pii,vector<pii>,greater<pii>> pq;

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

void input(){
    n  = fio::readInt(); m = fio::readInt();
    for(int i=0;i<m;i++){
        E[i].u = fio::readInt(); E[i].v = fio::readInt(); E[i].c = fio::readInt();
        G[ --E[i].u ].push_back(i);
        G[ --E[i].v ].push_back(i);
    }
    fill(dist,dist+n,inf);
}

void dijk(){
    pq.push({dist[0] = 0, 0});
    pii t;
    int x, c;
    while(!pq.empty()){
        t = pq.top(); pq.pop();
        if(t.va != dist[t.vb]) continue;
        for(int &e : G[t.vb]){
            x = E[e].op(t.vb);
            c = E[e].c;
            if(dist[x] > dist[t.vb] + c){
                dist[x] = dist[t.vb] + c;
                bck[x] = t.vb;
                pq.push({dist[x],x});
            }
        }
    }
}

void output(){
    printf("%d\n",n-1);
    for(int i=1;i<n;i++){
        printf("%d %d\n",i+1,bck[i]+1);
    }
}
int main(){
    input();
    dijk();
    output();
}