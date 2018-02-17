#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[505][505];
bool sagak(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%lld",&a[i][j]);
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i][j]+a[i-1][j-1]>a[i-1][j]+a[i][j-1]) return false;
        }
    }
    return true;
}
int main(){
    int t;
    for(scanf("%d",&t);t--;){
        if(sagak()) puts("YES");
        else puts("NO");
    }
}