#include <bits/stdc++.h>
using namespace std;
char str[200005], pat[100005];
int F[100005];
int n, cnt;
void input(){
    scanf("%s",str);
    scanf("%*c%s",pat);
    n=strlen(str);
    strncpy(str+n,str,n-1);
}
void build_failure(){
    int j = 0;
    for(int i=1;i<n;i++){
        for(;j&&pat[i]!=pat[j];j=F[j-1]);
        if(pat[i]==pat[j]) F[i]=++j;
    }
}
void kmp(){
    int j=0;
    for(int i=0;i<n+n-1;i++){
        for(;j>0&&str[i]!=pat[j];j=F[j-1]);
        if(str[i]==pat[j]){
            if(j==n-1) ++cnt,j=F[j];
            else ++j;
        }
    }
}
int main(){
    input();
    build_failure();
    kmp();
    printf("%d\n",cnt);
}