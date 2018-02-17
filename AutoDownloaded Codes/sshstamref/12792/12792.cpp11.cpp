#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1,j;i<=n;i++){
        cin>>j;
        if(j==i) exit(0*puts("-1"));
    }
    puts("1000000007");
}