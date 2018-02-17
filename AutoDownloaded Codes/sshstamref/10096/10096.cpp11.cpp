#include <bits/stdc++.h>
using namespace std;
const int mx=2e6+10;
int n,h;
char S[mx];
void nu(){exit(0*puts("NOT UNIQUE"));}
void np(){exit(0*puts("NOT POSSIBLE"));}
void input(){
    scanf("%d\n",&n);
    if(n%2==0) np();
    fgets(S,mx-4,stdin);
    S[n]=0; h=(n-1)>>1;
}
void solve(){
    int i,cnt=0;
    for(i=0;i<h&&S[i]==S[i+h];i++);
    for(;i<h&&S[i]==S[i+h+1];i++);
    if(i==h) cnt|=1;
    for(i=0;i<h&&S[i]==S[i+h+1];i++);
    for(;i<h&&S[i+1]==S[i+h+1];i++);
    if(i==h) cnt|=2;
    S[h]=0;
    switch(cnt){
    case 0: np();
    case 1: exit(0*puts(S));
    case 3: if(strcmp(S,S+h+1)) nu();
    case 2: exit(0*puts(S+h+1));
    }
}
int main(){
    input();
    solve();
}