#include <bits/stdc++.h>
char S[30];
int main(){
    int n, l;
    for(scanf("%d",&n);n--;){
        scanf("%*c%s",S);
        l = strlen(S);
        for(int i=0;i<l;i++) S[i] = tolower(S[i]);
        puts(S);
    }
}