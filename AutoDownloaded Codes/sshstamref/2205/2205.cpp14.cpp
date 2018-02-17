#include <bits/stdc++.h>
int N, a[10005];
void f(int n)
{
    if(n==0) return;
    if(n==1) {a[1] = 1; return;}
    int k  = 1;
    while(k<n) k<<=1;
    if(k==n) {a[n]=n, f(k-1);}
    else{
    for(int i=k-n;i<=n;i++) a[k-i]=i;
    f(k-n-1);
    }
}
int main()
{
    scanf("%d",&N);
    f(N);
    for(int i=1;i<=N;i++) printf("%d\n",a[i]);
}
