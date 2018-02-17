#include <bits/stdc++.h>
using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lf;

int n, k;
int p[10], h[10][10], mp;

void input(){
    for(int i=0;i<10;i++) for(int j=0;j<10;j++) h[i][j] = -1;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> p[i];
        mp = max(mp, p[i]);
        for(int j=0;j<p[i];j++){
            cin >> h[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=p[i];j<mp;j++){
            h[i][j] = 50;
        }
    }
}

void pro(){
    int tot = 0, s = 0;
    for(int j=0;j<mp;j++){
        for(int i=0;i<n;i++){
            if(h[i][j] >= tot){
                ++s;
                tot += h[i][j];
            }
            if(s == k) goto fin;
        }
    }
    fin:
    cout << (s == k ? tot : tot + 50 * (k-s)) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    pro();
}