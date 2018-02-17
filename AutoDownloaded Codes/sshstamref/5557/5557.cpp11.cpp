#include <cstdio>
int a[105];
long long d[105][21];
int main(){
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    d[0][a[0]]=1;
    for(int i=1;i<n-1;i++){
        for(int j=a[i];j<21;j++) d[i][j]+=d[i-1][j-a[i]];
        for(int j=0;j<21-a[i];j++) d[i][j]+=d[i-1][j+a[i]];
    }
    printf("%lld\n",d[n-2][a[n-1]]);
}