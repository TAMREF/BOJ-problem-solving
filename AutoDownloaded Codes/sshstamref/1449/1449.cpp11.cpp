#include <bits/stdc++.h>
using namespace std;
int a[1005], N, L, cnt;
int main(){
    scanf("%d%d",&N,&L);
    for(int i=0;i<N;i++) scanf("%d",&a[i]); sort(a,a+N);
    for(int j=0;j<N;cnt++){
        j=lower_bound(a,a+N,a[j]+L)-a;
    }
    printf("%d\n",cnt);
}
