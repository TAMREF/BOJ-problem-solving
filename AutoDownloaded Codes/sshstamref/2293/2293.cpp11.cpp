#include <cstdio>
#include <algorithm>
int d[10001]={1}, W[100];
int main(){
    int n, k; scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&W[i]); std::sort(W,W+n);
    for(int i=0;i<n;i++){
        for(int j=W[i];j<=k;j++) d[j]+=d[j-W[i]];
    }
    printf("%d\n",d[k]);
}
