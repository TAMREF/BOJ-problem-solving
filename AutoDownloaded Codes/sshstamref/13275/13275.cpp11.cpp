#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MX=1e5+3;
const char trash='*';
char buf[MX+5], cuf[2*MX+5]={trash};
int a[2*MX+5];
int Man(int N){
    for(int i=0;i<N;i++){
        cuf[2*i+1]=buf[i];
        cuf[2*i+2]=trash;
    }
    int r=0,p=0;
    for(int i=1;i<2*N+1;i++){
        if(i<=r) a[i]=min(r-i,a[p+p-i]);
        while(i>a[i]&&i+a[i]<2*N&&cuf[i+a[i]+1]==cuf[i-a[i]-1]) ++a[i];
        if(r<a[i]+i){
            p=i;
            r=a[i]+i;
        }
    }
    int s = max_element(a,a+2*N+1)-a;
    return 2*(a[s]/2)+(cuf[s]!=trash?1:0);
}
int main(){
    fgets(buf,MX,stdin);
    int N=strlen(buf);
    buf[--N]='\0';
    int u = Man(N);
    printf("%d\n",u);
}
