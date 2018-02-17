#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll a, D, ans;
int main(){
    scanf("%d",&N);
    scanf("%lld",&a);
    ans=D=a;
    for(int i=1;i<N;i++){
        scanf("%lld",&a);
        D = max(D+a,a);
        ans = max(ans,D);
    }
    printf("%lld\n",ans);
}