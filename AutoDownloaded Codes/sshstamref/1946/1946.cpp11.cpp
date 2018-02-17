#include <bits/stdc++.h>
using namespace std;
int tam[100005];
int main(){
    int t,n,thre,cnt;
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(cin>>t;t--;){
        cin>>n;
        for(int i=0,j;i<n;i++){cin>>j; cin>>tam[j-1];}
        thre = n+1, cnt=0;
        for(int i=0;i<n;i++){
            if(tam[i]<thre){
                ++cnt;
                thre=tam[i];
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}