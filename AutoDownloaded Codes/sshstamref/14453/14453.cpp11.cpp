#include <bits/stdc++.h>
using namespace std;
int s[100005], h[100005], p[100005];
int main(){
    int n;
    scanf("%d",&n);
    char x;
    for(int i=1;i<=n;i++){
        scanf("%*c%c",&x);
        s[i]=s[i-1]+(x=='S');
        h[i]=h[i-1]+(x=='H');
        p[i]=p[i-1]+(x=='P');
    }
    int win=0;
    for(int i=0;i<=n;i++){
        win=max({win,s[i]+h[n]-h[i],s[i]+p[n]-p[i],h[i]+s[n]-s[i],h[i]+p[n]-p[i],p[i]+s[n]-s[i],p[i]+h[n]-h[i]});
    }
    printf("%d\n",win);
}