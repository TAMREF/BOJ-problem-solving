#include <bits/stdc++.h>
using namespace std;
const int mx=1005;
char a[mx], b[mx];
int mygets(char* a, int n){
    fgets(a,n,stdin);
    int p=strlen(a);
    a[--p]=0;
    return p;
}
string lcs(string& a, string& b){
    int d[mx][mx], p[mx][mx];
    int N=a.size(), M=b.size();
    memset(d,0,sizeof(d));
    memset(p,0,sizeof(p));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(a[i-1]==b[j-1]) d[i][j]=d[i-1][j-1]+1, p[i][j]=3;
            else if(d[i-1][j]>=d[i][j-1]) d[i][j]=d[i-1][j],p[i][j]=2;
            else d[i][j]=d[i][j-1], p[i][j]=1;
        }
    }
    string c;
    while(p[N][M]){
        if(p[N][M]==3) c+=a[N-1];
        int dn=p[N][M]&2?1:0,dm=p[N][M]&1;
        N-=dn, M-=dm;
    }
    reverse(c.begin(),c.end());
    return c;
}
int main(){
    mygets(a,mx-4);
    mygets(b,mx-4);
    string u(a), v(b), l=lcs(u,v);
    cout<<l.size()<<endl<<l<<endl;
}