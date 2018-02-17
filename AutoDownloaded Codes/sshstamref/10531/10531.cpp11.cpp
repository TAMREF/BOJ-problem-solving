#include <bits/stdc++.h>
using namespace std;
typedef complex<double> cd;
typedef vector<cd> vcd;
typedef vector<int> poly;
int K[200005];
void dft(cd w, vcd& V){
    int n=V.size();
    if(n==1) return;
    vcd e(n>>1),o(n>>1);
    for(int i=0;i<V.size();i+=2) e[i>>1]=V[i], o[i>>1]=V[i+1];
    dft(w*w,e); dft(w*w,o);
    cd k(1,0);
    for(int i=0;i<n/2;i++){
        cd tmp=o[i]*k;
        V[i]=e[i]+tmp;
        V[i+n/2]=e[i]-tmp;
        k*=w;
    }
}
inline int up2(int n){
    int i=1;
    for(;i<n;i<<=1); return i;
}
poly operator* (poly& u, poly& v){
    int n=2*up2(max(u.size(),v.size()));
    vcd a(u.begin(),u.end()), b(v.begin(),v.end());
    a.resize(n); b.resize(n);
    cd w=exp(cd(0,1)*2.0*acos(-1)/(double)n);
    dft(w,a);
    dft(w,b);
    for(int i=0;i<n;i++) a[i]*=b[i];
    dft(pow(w,-1),a);
    for(int i=0;i<n;i++) a[i]/=(double)n;
    while(!a.empty() && fabs(real(a.back()))<1e-9) a.pop_back();
    poly fin(a.size());
    for(int i=0;i<fin.size();i++) fin[i]=(int)round(real(a[i]));
    return fin;
}
int main(){
    int N,M;
    vector<int> D(200005,0), E,G;
    scanf("%d",&N);
    for(int i=0,x;i<N;i++) scanf("%d",&x), D[x]=1;
    scanf("%d",&M);
    for(int i=0;i<M;i++) scanf("%d",&K[i]);
    E.assign(D.begin(),D.end());
    G.assign(E.begin(),E.end()); G[0]=1;
    poly F=E*G;
    int cnt=0;
    for(int i=0;i<M;i++) if(F[K[i]]) ++cnt;
    printf("%d\n",cnt);
}