#include <bits/stdc++.h>
using namespace std;
int main(){
int n,k,b=0;
cin>>n>>k;
while(__builtin_popcount(n)>k)
{
b+=n&-n;
n+=n&-n;
}
cout<<b<<endl;
}