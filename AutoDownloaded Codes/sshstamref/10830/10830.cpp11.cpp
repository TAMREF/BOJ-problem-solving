#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
typedef long long ll;
struct mat{
    int n;
    vector<int> hor[5], ver[5];
    mat(int n,vvi V):n(n){
        for(int i=0;i<n;i++) hor[i]=V[i];
        for(int j=0;j<n;j++) for(int i=0;i<n;i++) ver[j].push_back(hor[i][j]);
    }
    mat operator* (mat z){
        assert(n==z.n);
        vvi H(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                H[i][j]=inner_product(hor[i].begin(),hor[i].end(),z.ver[j].begin(),0)%1000;
        return mat(n,H);
    }
};
int main(){
    int N; ll B;
    cin>>N>>B;
    vector<mat> P;
    vvi U(N,vector<int>(N)),E(N,vector<int>(N));
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) scanf("%d",&U[i][j]),E[i][j]=(i==j?1:0);
    P.push_back(mat(N,U));
    for(int i=0;1LL<<i<=B;i++){
        mat tmp=P.back();
        P.push_back(tmp*tmp);
    }
    mat I=mat(N,E);
    for(int i=0;1LL<<i<=B;i++){
        if(B&1LL<<i) I=I*P[i];
    }
    for(int i=0;i<N;i++,puts("")) for(int j=0;j<N;j++) printf("%d ",I.hor[i][j]);
}