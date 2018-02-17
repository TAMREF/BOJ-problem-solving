#include <bits/stdc++.h>
using namespace std;
int a[100005], i,s;
int main(){
   for(;scanf("%1d",&a[i++])==1;);
   sort(a,a+i-1,greater<int>());
   for(int j=0;j<i-1;j++) s+=a[j];
   if(a[i-2]!=0||s%3) return 0*puts("-1");
   else for(int j=0;j<i-1;j++) printf("%d",a[j]);
}
