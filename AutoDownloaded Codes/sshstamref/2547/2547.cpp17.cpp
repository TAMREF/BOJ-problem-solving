#include <cstdio>
typedef long long ll;

int main(){
    int n, t;
    ll x;
    for(scanf("%d",&t);t--;){
        scanf("%d",&n);
        ll sum = 0;
        for(int i=0;i<n;i++){
            scanf("%lld",&x);
            sum = (sum + x % n) % n;
        }
        puts(sum?"NO":"YES");
    }
}