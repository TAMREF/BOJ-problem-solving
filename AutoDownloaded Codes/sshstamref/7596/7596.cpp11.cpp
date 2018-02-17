#include <bits/stdc++.h>
using namespace std;

string S[205];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,t=1;
    for(;;t++){
        cin >> n;
        if(!n) return 0;
        getline(cin,S[0]);
        for(int i=0;i<n;i++){
            getline(cin,S[i]);
        }
        sort(S,S+n);
        cout << t << '\n';
        for(int i=0;i<n;i++){
            cout << S[i] << '\n';
        }
    }
}