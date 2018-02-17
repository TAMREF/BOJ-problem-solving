#include <bits/stdc++.h>
using namespace std;
int n, a[10005];
int main(){
    scanf("%d",&n); for(int i=0;i<n;i++) scanf("%d",&a[i]);
    if(prev_permutation(a,a+n)) for(int i=0;i<n;i++) printf("%d ",a[i]);
    else puts("-1");
    return 0;
}