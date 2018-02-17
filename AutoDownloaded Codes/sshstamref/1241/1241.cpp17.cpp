#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+5;
const int mnum = 1e6+5;

int a[mx], cnt[mnum], ans[mx];
int divi[2005], tau;
int n;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        ++cnt[a[i]];
    }
    for(int i=0;i<n;i++){
        tau = 0;
        int j = 1;
        for(;j*j<a[i];j++){
            if(a[i] % j == 0){
                divi[tau++] = j;
                divi[tau++] = a[i] / j;
            }
        }
        if(j*j==a[i]) divi[tau++] = j;

        for(int t=0;t<tau;t++) ans[i] += cnt[divi[t]];
        cout << ans[i] - 1 << '\n';
    }
    return 0;
}
