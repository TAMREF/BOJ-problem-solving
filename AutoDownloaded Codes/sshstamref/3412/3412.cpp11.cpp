#include <bits/stdc++.h>
using namespace std;

int t,n,x,y,sum;
int lb[10];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    iota(lb,lb+10,1);
    for(int i=0;i<10;i++) lb[i] *= 20, lb[i] *= lb[i];

    for(cin>>t;t--;){
        sum = 0;
        for(cin>>n;n--;){
            cin>>x>>y;
            sum += ( 10 - ( lower_bound( lb, lb+10, x*x+y*y ) - lb ) );
        }
        cout<< sum << '\n';
    }
}
