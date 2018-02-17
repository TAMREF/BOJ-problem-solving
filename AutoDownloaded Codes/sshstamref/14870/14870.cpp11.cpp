#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 1505;

ll dpval = 0;
struct RRBIT{
    ll f[mx], d[mx];
    int n;
    RRBIT(){}
    RRBIT(int n, ll *p):n(n){
        copy(p+1, p+n+1, d+1);
    }
    void upd(int i, ll v){
        for(;i<=n;i+=(i&-i)) f[i] += v;
    }
    void upd(int a, int b, ll v){
        upd(a,v);
        upd(b+1,-v);
        dpval += v * (b-a+1);
    }
    ll gsum(int i){
        ll s = d[i];
        for(;i;i-=(i&-i)) s += f[i];
        return s;
    }
} I[mx];

ll dp[mx][mx], sh[mx][mx];

inline ll t(int i, int j){
    return I[i].gsum(j);
}

inline void u(int i, int x, int y, int v){
    return I[i].upd(x,y,v);
}

int n;
int s[mx], e[mx];

void input(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> sh[i][j];
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + sh[i][j];
            dpval += dp[i][j];
        }
        I[i] = RRBIT(n, dp[i]);
    }
    cout << dpval << '\n';
}

void query(){
    char c;
    for(int i=1,x,y;i<=n;i++){
        cin >> c >> x >> y;
        assert(c == 'D' || c == 'U');
        c = (c == 'U');
        s[x] = y; e[x] = y + 1;
        for(;e[x] <= n;e[x]++){
            if(x==1) continue;
            if(c && t(x,e[x]-1) < t(x-1,e[x]) || !c && t(x,e[x]-1) <= t(x-1,e[x])) break;
        }
        for(int j = x+1;j<=n;++j){
            s[j] = s[j-1]; e[j] = e[j-1];

            for(;s[j] < e[j]; s[j]++){

                if(s[j]==1) break;

                if(c && t(j,s[j]-1) <= t(j-1,s[j]) || !c && t(j,s[j]-1) < t(j-1,s[j])) break;

            }
            if(s[j] >= e[j]) break;

            for(;e[j] <= n; e[j]++){
                if(c && t(j,e[j]-1) < t(j-1,e[j]) || !c && t(j,e[j]-1) <= t(j-1,e[j])) break;
            }        
        }
        for(int j=x;j<=n;j++){
            if(s[j] >= e[j]) break;
            u(j, s[j], e[j]-1, 2*c-1);
        }
        cout << dpval << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    query();
}
