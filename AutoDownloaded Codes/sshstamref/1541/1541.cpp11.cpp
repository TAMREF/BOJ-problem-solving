#include <bits/stdc++.h>
using namespace std;
char buf[100];
int main(){
    scanf("%s",buf);
    int x=0,S=0,flag=0;
    for(int i=0;buf[i]!=0;++i){
        if('0'<=buf[i] && buf[i]<='9')
            x=10*x+(buf[i]&15);
        if(buf[i]=='-'){
            S+=(flag?-x:x);
            x=0;
            flag=1;
        }
        if(buf[i]=='+'){
            S+=(flag?-x:x);
            x=0;
        }
    }
    S+=(flag?-x:x);
    printf("%d\n",S);
}