#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,cnt=0; cin>>n;
    for(int i=1,x;i<=n;i++){
        cin>>x;
        if(x!=i) ++cnt;
    }
    cout<<cnt<<endl;
}