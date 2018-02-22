#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e8 + 7;
const int mx = 720005;

int fail[mx], deg[mx], buf[mx];
int n, p;

ll lpow(int a, int n){
    ll ret = 1, pv = a % mod;
    for(;n;n>>=1){
        if(n & 1) ret = ret * pv % mod;
        pv = pv * pv % mod;
    }
    return ret;
}

int init(){
    cin >> n >> p;
    if(n == -1){
        exit(0);
    }
    if(p == 1){
        cout << n << '\n';
        return 0;
    }
    for(int i = 0; i < p; i++) cin >> buf[i];
    sort(buf,buf+p); buf[p] = buf[0] + 360000;
    for(int i = 1; i <= p; i++){
        deg[i-1] = buf[i] - buf[i-1];
    }
    for(int i = 0; i < p; i++) deg[i+p] = deg[i];
    return 1;
}

void buildFail(){
    for(int i = 1, j = 0; i < p; i++){
        while(j > 0 && deg[i] != deg[j]){
            j = fail[j-1];
        }
        if(deg[i] == deg[j]){
            fail[i] = ++j;
        }
    }
}

void solve(){
    int ans = 0;
    int cnt = 0;
    buildFail();
    for(int i = 0, j = 0; i < p + p - 1; i++){
        while(j > 0 && deg[i] != deg[j]) j = fail[j-1];
        if(deg[i] == deg[j]){
            if(j == p-1){
                ans = (ans + lpow(n, __gcd(i+1,p))) % mod;
                ++cnt;
                j = fail[j];
            } else ++j;
        }
    }
    cout << (ll)ans * lpow(cnt, mod-2) % mod << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int numi = 0;;numi += p){
        if(init()) solve();
    }
}
