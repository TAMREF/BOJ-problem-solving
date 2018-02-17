#include <bits/stdc++.h>
using namespace std;

char tar[15], S[30];
int n, len;

int main(){
    scanf("%s",tar);
    scanf("%*c%d",&n);
    int ans = 0;
    for(int i=0;i<n;i++){
        scanf("%*c%s",S);
        for(int i=0;i<10;i++) S[10+i] = S[i];
        S[20] = 0;
        if(strstr(S,tar)) ++ans;
    }
    printf("%d\n",ans);
}