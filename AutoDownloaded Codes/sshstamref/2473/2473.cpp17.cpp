#include <bits/stdc++.h>
using namespace std;
 
typedef long long lld;
int n;
lld num[5005];
int main()
{
    int a=0,b=1,c=2;
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%lld",&num[i]);
    sort(num,num+n);
    for(int i=0;i<n-2;++i){
        int l = i+1;
        int r = n-1;
        int x=l,y=r;
        while(l<r){
            if(abs(num[l]+num[r]+num[i])<abs(num[x]+num[y]+num[i])){
                x=l;
                y=r;
            }
            if(num[l]+num[r]+num[i]>0)--r;
            else ++l;
        }
        if(abs(num[i]+num[x]+num[y])<abs(num[a]+num[b]+num[c])){
            a=i;
            b=x;
            c=y;
        }
    }
    printf("%lld %lld %lld",num[a],num[b],num[c]);
}
