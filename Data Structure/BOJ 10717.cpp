#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int mx = 4005;

struct BIT{
    short int d[mx * mx + mx + mx];
    short int *a, n = 0;
    void init(int h=mx-1){
        a += n;
        n = h;
    }
    int gsum(int i){
        if(!i) return 0;
        int s = 0;
        for(;i;i-=i&-i) s += a[i];
        return s;
    }
    ll gsum(int i, int j){
        if(i>j) return 0;
        return gsum(j)-gsum(i-1);
    }
    void add1(int i){
        for(;i<=n;i+=(i&-i)) ++a[i];
    }
} I;

bool E[mx][mx];
short int C[mx][mx][4]; //nesw
int h, w, l, p;
ll ans;

void input(){
    cin >> h >> w >> l >> p;
    for(int i=0,r,c;i<p;i++){
        cin >> r >> c;
        E[r][c] = 1;
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++) C[i][j][3] = (!E[i][j]) * (C[i][j-1][3] + 1);
        for(int j=w;j>=1;j--) C[i][j][1] = (!E[i][j]) * (C[i][j+1][1] + 1);
    }
    for(int j=1;j<=w;j++){
        for(int i=1;i<=h;i++) C[i][j][0] = (!E[i][j]) * (C[i-1][j][0] + 1);
        for(int i=h;i>=1;i--) C[i][j][2] = (!E[i][j]) * (C[i+1][j][2] + 1);
    }
}

void work(){
    vector<pii> seg;
    seg.reserve(mx+mx);
    for(int p = 1-h; p <= w-1; p++){
        seg.clear();
        for(int i=1,j;i<=h;i++){
            j = i + p;
            if(j > w) break;
            if(j <= 0 || E[i][j]) continue;
            seg.emplace_back(i - min(C[i][j][0],C[i][j][3]) + 1, i);
        }
        sort(seg.begin(),seg.end());
        I.init(h);
        int sid = 0;
        for(int i=1,j;i<=h;i++){
            j = i + p;
            if(j > w) continue;
            if(j <= 0 || E[i][j]) continue;
            for(int c=seg.size();sid < c && seg[sid].first <= i;++sid){
                I.add1(seg[sid].second);
            }
            ans += I.gsum(i+l-1,i+min(C[i][j][1],C[i][j][2])-1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    work();
    cout << ans << endl;
}
