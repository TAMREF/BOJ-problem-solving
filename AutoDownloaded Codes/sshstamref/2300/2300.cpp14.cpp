#include <bits/stdc++.h>
#define wall 2147483647
using namespace std;
int D[11111];
pair<int,int> tam[11111];
int N;
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++) scanf("%d%d",&tam[i].first,&tam[i].second);
    sort(tam+1,tam+N+1);
    for(int i=1;i<=N;i++){
        D[i]=wall;
        int big = abs(2*tam[i].second);
        for(int j=i-1;j>=0;j--){
            big = max(big,abs(2*tam[j+1].second));
            D[i]=min(D[i],D[j]+max(big,tam[i].first-tam[j+1].first));
        }
    }
    printf("%d\n",D[N]);
}