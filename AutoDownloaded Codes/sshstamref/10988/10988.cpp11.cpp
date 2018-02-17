#include <bits/stdc++.h>
using namespace std;
char buf[101], str[303];
int main(){
    scanf("%s",buf);
    int i, len=strlen(buf);
    for(i=0;i<len;i++){
        str[2*i]=buf[i];
        str[2*i+1]='*';
    }
    for(i=0;i<len;i++){
        if(str[i]!=str[2*len-2-i]) return 0*puts("0");
    }
    return 0*puts("1");
}