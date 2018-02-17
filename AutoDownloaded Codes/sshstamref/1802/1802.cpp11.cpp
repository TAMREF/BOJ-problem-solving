#include <bits/stdc++.h>
using namespace std;

int t,n;
char S[3005];

int main(){
    for(scanf("%d",&t);t--;){
        scanf("%*c%s",S);
        n = strlen(S);
        int flag = 1;
        while(n>1){
            for(int i=0;i<n/2;i++){
                if(S[n/2-1-i] == S[n/2+1+i]){
                    flag = 0;
                    goto out;
                }
            }
            n /= 2;
        }
        out:
        puts(flag ? "YES" : "NO");
    }
}
