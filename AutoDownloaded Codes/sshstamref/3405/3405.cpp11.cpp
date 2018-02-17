#include <bits/stdc++.h>
using namespace std;

const int mx = 20;

bool dp[1<<mx];

int rsum[mx], psum[mx][1<<mx];

int n, mask;

void init(){
    memset(dp,0,sizeof(dp));
    //memset(psum,0,sizeof(psum));
    memset(rsum,0,sizeof(rsum));

    cin>>n;
    mask = (1<<n) - 1;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> psum[i][1<<j];
            rsum[i] += psum[i][1<<j];
        }
    }

    for(int i=0, t;i<n;i++){

        for(int b=0;b<(1<<n);b++){
            t = b & -b;
            psum[i][b] = psum[i][b^t] + psum[i][t];
        }

    }
}

void work(){
    dp[0] = true;

    for(int b = 0 ; b <= mask ; b++){
        if(!dp[b]) continue;
        for(int i = 0 ; i < n ; i++){
            if( b>>i & 1 ) continue;
            if( rsum[i] - psum[i][b] > 0 ) dp[b | 1<<i] = true;
        }
    }

    int f = 1;
    for(int i = 0 ; i < n ; i++){
        if( dp[mask ^ (1<<i)] ){
            f = 0;
            cout<<i+1<<' ';
        }
    }
    if(f) cout<<0;
    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    assert( t <= 10000 );
    for(;t--;){
        init();
        work();
    }
}
