#include <bits/stdc++.h>
using namespace std;
queue<int> Q;
int n,k;
bool possible[360];
int know[10];
int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>know[i];
        Q.push(know[i]);
    }
    for(int t;!Q.empty();){
        t=Q.front(); Q.pop();
        if(!possible[t]){
            possible[t]=true;
            for(int i=0;i<10;i++){
                Q.push((t+know[i])%360);
                Q.push((t-know[i]+360)%360);
            }
        }
    }
    for(int i=0,x;i<k;i++){
        cin>>x;
        puts(possible[x]?"YES":"NO");
    }
}