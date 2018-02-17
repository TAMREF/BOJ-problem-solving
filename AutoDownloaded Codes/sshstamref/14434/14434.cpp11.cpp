#include <bits/stdc++.h>
using namespace std;

int lim[200005], psum[200005];
vector<int> grow[200005];
int n, m, k, q;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k >> q;
    for(int i=1;i<=m;i++) cin>>lim[i];
    for(int i=1,x;i<=k;i++){
        cin>>x;
        grow[x].push_back(i);
    }
    for(int i=0,a,b,c;i<q;i++){
        cin >> a >> b >> c;
        int lo = 1, mi, hi = k+1;
        while(lo < hi){
            mi = (lo + hi) >> 1;
            int xx = upper_bound(grow[a].begin(),grow[a].end(),mi) - grow[a].begin();
            int yy = upper_bound(grow[b].begin(),grow[b].end(),mi) - grow[b].begin();
            if(xx + yy >= lim[c]) hi = mi;
            else lo = mi + 1;
        }
        psum[lo]++;
    }
    for(int i=1;i<=k;i++){
        psum[i] += psum[i-1];
        cout << psum[i] << '\n';
    }
}