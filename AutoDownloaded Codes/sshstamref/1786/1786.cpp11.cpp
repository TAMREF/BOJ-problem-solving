#include <bits/stdc++.h>
using namespace std;
const int MX=1000005;
int pal[MX], ans[MX], top, N, M;
string tex,pat;
void setpal(){
    for(int i=1,j=0;i<M;++i){
        for(;j&&pat[i]!=pat[j];j=pal[j-1]);
        if(pat[i]==pat[j]) pal[i]=++j;
    }
}
void kmp(){
    for(int i=0,j=0;i<N;++i){
        for(;j&&(tex[i]!=pat[j]);j=pal[j-1]);
        if(tex[i]==pat[j]){
            if(j==M-1){
                ans[top++]=i-M+1;
                j=pal[j];
            }
            else ++j;
        }
    }
}
int main(){
    cin.sync_with_stdio(false);
    getline(cin,tex);
    getline(cin,pat);
    N=tex.size(), M=pat.size();
    setpal();
    kmp();
    for(int i=0*printf("%d\n",top);i<top;i++) printf("%d ",ans[i]+1);
}
