#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;

typedef pair<int,int> pii;

pii tam[50005];
int n;

void input(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> tam[i].va >> tam[i].vb;
    sort(tam,tam+n);
}

void pro(){
    vector<pii> curr;
    int c = 1, ca = tam[0].va, m = tam[0].vb;
    for(int i=1;i<n;i++){
        if(tam[i].va > m){
            ++c;
            curr.emplace_back(ca, m);
            ca = tam[i].va;
            m = tam[i].vb;
        }else{
            m = max(m, tam[i].vb);
        }
    }
    curr.emplace_back(ca,m);
    for(pii &p : curr){
        cout << p.va << ' ' << p.vb << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    pro();
}
