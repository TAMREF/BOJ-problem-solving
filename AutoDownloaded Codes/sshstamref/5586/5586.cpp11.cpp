#include <bits/stdc++.h>
using namespace std;
char a[10005];
int main(){
    scanf("%s",a);
    int n=strlen(a),ic=0,jc=0;
    for(int i=0;i<n-2;i++){
        if(!strncmp("IOI",a+i,3)) ++ic;
        if(!strncmp("JOI",a+i,3)) ++jc;
    }
    printf("%d\n%d\n",jc,ic);
}