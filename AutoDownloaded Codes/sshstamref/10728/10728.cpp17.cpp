#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("sample.txt","rt",stdin);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 0;
    for(cin >> t ; t-- ; ){
        int n, ans = 0 , ab = 0;
        cin >> n;
        for(int b=1;b<(1<<n);b++){
            for(int i=0;i<n;i++){
                if((b>>i&1) == 0) continue;
                for(int j=i+1;j<n;j++){
                    if((b>>j&1) && (b>>( ((i+1)^(j+1))-1 )&1)) goto FAIL;
                }
            }
            if(__builtin_popcount(b) > ans){
                ans = __builtin_popcount(b);
                ab = b;
                continue;
            }
            FAIL:
                ab = ab;
        }
        printf("%d\n",ans);
        for(int i=0;i<n;i++) if(ab>>i&1) printf("%d ",i+1);
        puts("");
    }
}
