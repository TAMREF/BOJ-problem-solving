#include <bits/stdc++.h>
#define kill() exit(0*puts("-1"))
using namespace std;
int d[25][25],sp[25][25],i,j,k,n;
int main(){
    cin>>n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>sp[i][j];
        }
    }
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i==j||j==k||k==i)
                    continue;
                if(sp[i][j]>sp[i][k]+sp[k][j])
                    kill();
                if(sp[i][j]==sp[i][k]+sp[k][j])
                    d[i][j]=1;
            }
        }
    }
    int l=0;
    for(i=0;i<n;i++) for(j=0;j<n;j++) l+=(!d[i][j])*sp[i][j];
    cout<<l/2<<endl;
}