#include <iostream>
using namespace std;
typedef long long ll;
const int mx = 100005;
const ll mod = 1e9+7;

ll D[mx][3];

ll n, cnt[mx];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin>>n;
    for(int i=0,x;i<n;i++){
        cin>>x;
        ++cnt[x];
    }

    for(int i=1;i<=100000;i++){
        D[i][0] = (D[i-1][0] + (cnt[i] * i % mod)) % mod;
        D[i][1] = (D[i-1][1] + ((D[i-1][0] * cnt[i] % mod) * i % mod)) % mod;
        D[i][2] = (D[i-1][2] + ((D[i-1][1] * cnt[i] % mod) * i % mod)) % mod;
    }

    cout<<D[100000][2]<<endl;
}
