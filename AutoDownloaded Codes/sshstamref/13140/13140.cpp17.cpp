#include <bits/stdc++.h>
#define dd p[0]
#define ee p[1]
#define hh p[2]
#define ll p[3]
#define oo p[4]
#define rr p[5]
#define ww p[6]
using namespace std;

int p[10];
int n;
bool eval(){
    return hh && ww && n == (10000 * (hh+ww) + 1000 * (ee + oo) + 100 * (ll + rr) + 10 * (ll + ll) + (oo + dd));
}

int main(){
    iota(p,p+10,0);
    scanf("%d",&n);
    do{
        if(eval()){
            printf("  %d%d%d%d%d\n",hh,ee,ll,ll,oo);
            printf("+ %d%d%d%d%d\n",ww,oo,rr,ll,dd);
            printf("-------\n");
            printf("%7d\n",n);
            return 0;
        }
    }while(next_permutation(p,p+10));
    puts("No Answer");
}