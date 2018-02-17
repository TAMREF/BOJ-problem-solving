#include <bits/stdc++.h>
using namespace std;
int cmp[103][103], n,m;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int a,b;m--;){
        cin>>a>>b;
        cmp[a][b]=1, cmp[b][a]=-1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(cmp[i][k] && cmp[i][k]==cmp[k][j]){
                    cmp[i][j]=cmp[i][k];
                }
            }
        }
    }
    for(int i=1;i<=n;i++) printf("%d\n",count(cmp[i]+1,cmp[i]+n+1,0)-1);
}