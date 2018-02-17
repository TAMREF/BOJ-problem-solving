#include <bits/stdc++.h>
#define gc getchar_unlocked
using namespace std;
int readInt(){
    int x = 0;
    char c = gc();
    while(c<'0'||c>'9') c = gc();
    while(c>='0' && c<='9'){
        x = (x<<3) + (x<<1) + (c&15);
        c = gc();
    }
    return x;
}
int n, cnt[2001], dnt[4001], m;
int main(){
    for(n = readInt();n--;++cnt[readInt()]);
    for(int i=0;i<=2000;i++){
        dnt[i+i] += cnt[i]/2;
        for(int j=i+1;j<=2000;j++) dnt[i+j] += min(cnt[i],cnt[j]);
    }
    m = *max_element(dnt,dnt+4001); printf("%d %d\n",m,count(dnt,dnt+4001,m));
}