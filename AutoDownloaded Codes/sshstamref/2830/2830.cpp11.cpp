#include <stdio.h>
#define gc getchar_unlocked
inline int readInt(){
    register int n=0,c=gc();
    while(c<'0'||c>'9') c=gc();
    while(c<='9'&&c>='0'){
        n=n*10+(c&15);
        c=gc();
    }
    return n;
}
int a[20];
int main(){
    int N=readInt(),x;
    long long ans=0;
    for(int i=0;i<N;i++){
        x=readInt();
        for(int now=0;x;x>>=1) a[now++]+=x&1;
    }
    for(int i=0;i<20;i++) ans+=1LL*a[i]*(N-a[i])<<i;
    printf("%lld\n",ans);
}