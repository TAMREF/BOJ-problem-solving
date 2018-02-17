#include <bits/stdc++.h>
using namespace std;

struct BIT{
    int a[500005], n;
    int sum(int i){
        int s = 0;
        for(;i;i&=i-1) s += a[i];
        return s;
    }
    void inc(int i){
        for(;i<=n;i+=(i&-i)) ++a[i];
    }
} I;

int rnk[500005], val[500005];

void input(){
    int &n = I.n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> rnk[i];
        val[i] = rnk[i];
    }
    sort(val,val+n);
    for(int i=0;i<n;i++) rnk[i] = lower_bound(val,val+n,rnk[i]) - val + 1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    for(int i=0;i<I.n;i++){
        cout << i + 1 - I.sum(rnk[i]) << '\n';
        I.inc(rnk[i]);
    }
}
