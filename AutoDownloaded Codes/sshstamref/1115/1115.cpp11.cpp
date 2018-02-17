#include <bits/stdc++.h>
using namespace std;

int n, P[55], cyc, vis[55];

int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>P[i];
    for(int i=0;i<n;i++){
        if(!vis[i]){
            ++cyc;
            int j=i;
            while(!vis[P[j]]){
                vis[P[j]] = 1;
                j = P[j];
            }
        }
    }
    cout<<(cyc==1?0:cyc)<<endl;
}