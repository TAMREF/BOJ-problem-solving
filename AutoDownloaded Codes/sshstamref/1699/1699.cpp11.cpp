#include <bits/stdc++.h>
using namespace std;
int D[100005];
int main(){
    int N;scanf("%d",&N);
    memset(D,0xF,sizeof(D));
    D[0]=0;
    for(int i=2;i<=N;i++) for(int j=1;j*j<=i;j++) D[i]=min(D[i],1+D[i-j*j]);
    printf("%d\n",D[N]);
}
