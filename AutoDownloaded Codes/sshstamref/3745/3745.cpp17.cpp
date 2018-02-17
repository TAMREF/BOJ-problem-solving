#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    vector<int> lis;
    int t,n,x;
    for(;;){
        lis.clear();
        lis.push_back(INT_MIN);
        if(!(cin >> n)) break;
        for(int i=0;i<n;i++){
            cin >> x;
            if(lis.back() < x) lis.push_back(x);
            else *lower_bound(lis.begin(),lis.end(),x) = x;
        }
        cout << (int)lis.size() - 1 << '\n';
    }
}
