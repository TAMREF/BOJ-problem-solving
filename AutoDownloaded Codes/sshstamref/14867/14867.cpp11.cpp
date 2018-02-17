#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;

typedef pair<int,int> pii;
const int inf = -1e8;

int a, b, ta, tb;
map<pii,int> m;

void input(){
    cin >> a >> b >> ta >> tb;
    if(ta !=0 && ta != a && tb != 0 && tb != b){
        puts("-1");
        exit(0);
    }
    if(ta == 0 && tb == 0){
        puts("0");
        exit(0);
    }
}

void BFS(){
    queue<pii> Q;
    m[{0,0}] = inf;
    Q.emplace(0,0);
    pii t;
    while(!Q.empty()){
        t = Q.front(); Q.pop();
        //cout << t.va << ' ' << t.vb << '\n';
        if(ta == t.va && tb == t.vb) break;
        int v = m[{t.va,t.vb}];
        if(m[{a,t.vb}] > v + 1){
            m[{a,t.vb}] = v + 1;
            Q.emplace(a,t.vb);
        }
        if(m[{0,t.vb}] > v + 1){
            m[{0,t.vb}] = v + 1;
            Q.emplace(0,t.vb);
        }
        if(m[{t.va,b}] > v + 1){
            m[{t.va,b}] = v + 1;
            Q.emplace(t.va,b);
        }
        if(m[{t.va,0}] > v + 1){
            m[{t.va,0}] = v + 1;
            Q.emplace(t.va,0);
        }
        if(t.va >= b - t.vb){
            if(m[{t.va + t.vb - b, b}] > v + 1){
                m[{t.va + t.vb - b, b}] = v + 1;
                Q.emplace(t.va + t.vb - b, b);
            }
        }else{
            if(m[{0, t.va +t.vb}] > v + 1){
                m[{0, t.va + t.vb}] = v + 1;
                Q.emplace(0, t.va + t.vb);
            }
        }
        if(t.vb >= a - t.va){
            if(m[{a, t.va + t.vb - a}] > v + 1){
                m[{a, t.va + t.vb - a}] = v + 1;
                Q.emplace(a, t.va + t.vb - a);
            }
        }else{
            if(m[{t.va+t.vb,0}] > v + 1){
                m[{t.va + t.vb, 0}] = v + 1;
                Q.emplace(t.va + t.vb, 0);
            }
        }
    }
    cout << (m[{ta,tb}]?m[{ta,tb}]-inf:-1) << endl;
}

int main(){
    input();
    BFS();
}