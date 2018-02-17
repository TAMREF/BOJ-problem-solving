#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[32768][100];

ll ten[5005];

string raw_a[15];
ll a[15];
ll fac = 1;
int n, k;

void init(){
    cin>>n;
    for(int i=2;i<=n;i++) fac = fac * i;
    getline(cin,raw_a[0]);
    for(int i=0;i<n;i++){
        getline(cin,raw_a[i]);
    }
    cin>>k;

    ten[0] = 1;
    for(int i=1;i<=5000;i++){
        ten[i] = ten[i-1] * 10LL % k;
    }
    for(int i=0;i<n;i++){
        for(char c : raw_a[i]){
            a[i] = (10LL *a[i] + c - '0') % k;
        }
    }
}

void dp_fill(){
    dp[0][0] = 1;
    for(int b = 0; b < (1<<n); b++){
        int len = 0;
        for(int i = 0; i < n; i++){
            if(b >> i & 1){
                len += raw_a[i].size();
            }
        }
        for(int i = 0; i < n; i++){
            if(b >> i & 1) continue;
            for(int m = 0; m < k; m++){
                dp[b | 1<<i][(m + ten[len] * a[i])%k] += dp[b][m];
            }
        }
    }
    /*
    for(int b = 0; b< (1<<n); b++){
        cout<<"state "<<b<<" : ";
        for(int j=0;j<k;j++) cout<<dp[b][j]<<" ";
        cout<<"\n";
    }*/
    ll ja = dp[(1<<n)-1][0], g = __gcd(ja, fac);
    cout<< ja/g << "/" << fac/g << endl;
}

int main(){
    init();
    dp_fill();
}
