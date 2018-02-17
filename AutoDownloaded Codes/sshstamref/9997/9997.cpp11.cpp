#include <bits/stdc++.h>
using namespace std;
int bit[25], n, l;
char buf[105];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%*c%s",buf);
        l=strlen(buf);
        for(int j=0;j<l;j++) bit[i]|=1<<buf[j]-'a';
    }
    int cnt=0;
    for(int i=0,b=(1<<n)-1,m;i<=b;i++){
        m=0;
        for(int j=0;j<n;j++){
            m|=(i&1<<j?bit[j]:0);
            if(m==67108863){
                ++cnt;
                break;
            }
        }
    }
    printf("%d\n",cnt);
}