#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b; scanf("%d%d",&a,&b);
    printf("%d\n%d",__gcd(a,b),a*b/__gcd(a,b));
}