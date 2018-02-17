#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    while(1){
        scanf("%d%d",&a,&b);
        if(!a && !b) return 0;
        printf("%d\n",min({30*a+40*b,35*a+30*b,40*a+20*b}));
    }
}