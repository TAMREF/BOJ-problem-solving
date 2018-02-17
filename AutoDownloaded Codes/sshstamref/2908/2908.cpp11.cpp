#include <bits/stdc++.h>
using namespace std;
char a[4], b[4];
int main(){
    scanf("%s %s",a,b);
    reverse(a,a+3), reverse(b,b+3);
    puts(lexicographical_compare(a,a+3,b,b+3)?b:a);
}