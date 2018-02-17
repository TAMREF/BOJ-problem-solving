#include <bits/stdc++.h>
using namespace std;

namespace DynamicSegtree{
    int st, en, n, d, x, y;
    struct node{
        int v, s, e;
        node *l, *r;
        node() {}
        node(int v, int s, int e):v(v),s(s),e(e),l(0),r(0) {}
        void update(){
            if(s > en || e < st) return;
            if(v == e - s + 1) return;
            if(st <= s && e <= en){
                v = e - s + 1; return;
            }
            int m = (s+e)/2;
            if(!l) l = new node(0,s,m);
            if(!r) r = new node(0,m+1,e);

            l->update();
            r->update();

            v = l->v + r->v;
        }
        int query(){
            if(s > en || e < st) return 0;
            if(v == e - s + 1){
                return min(e,en) - max(s,st) + 1;
            }
            if(st <= s && e <= en) return v;
            int m = (s+e)/2;
            if(!l) l = new node(0,s,m);
            if(!r) r = new node(0,m+1,e);
            return l->query() + r->query();
        }
    };
}

using namespace DynamicSegtree;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, c = 0;
    node *root = new node(0,1,1<<30);
    cin >> n;
    for(int ty; n--; ){
        cin >> ty >> st >> en;
        st += c; en += c;
        if(ty == 1){
            c = root->query();
            cout << c << '\n';
        }else{
            root->update();
        }
    }
}
