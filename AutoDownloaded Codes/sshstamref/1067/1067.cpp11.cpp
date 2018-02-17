#include <bits/stdc++.h>
#define PI 3.1415926535897932384626
using namespace std;
typedef complex<double> cd;
typedef int fft_t;
typedef vector<fft_t> poly;
const cd j = cd(0,1);
const cd one = cd(1,0);
inline int pow2(int x){
    int s=1;
    for(;s<x;) s<<=1;
    return s;
}
void dft(cd w, vector<cd>& v){
    int h = v.size()>>1;
    if(!h) return;
    cd k = one;
    vector<cd> o(h), e(h);
    for(int i=0;i<h;i++){
        e[i]=v[i<<1];
        o[i]=v[i<<1|1];
    }
    dft(w*w,e);
    dft(w*w,o);
    for(int i=0;i<h;i++){
        v[i]=e[i]+k*o[i];
        v[i+h]=e[i]-k*o[i];
        k*=w;
    }
}
void fft(poly &u, poly &v, poly &ret){
    int n=2*pow2(max(u.size(),v.size()));
    u.resize(n); v.resize(n); ret.resize(n);
    vector<cd> a(n), b(n), c(n);
    for(int i=u.size();i--;) a[i]=u[i];
    for(int i=v.size();i--;) b[i]=v[i];
    cd w = exp(j*PI*2.0/(double)n);
    dft(w,a); dft(w,b);
    for(int i=0;i<n;i++) c[i]=a[i]*b[i];
    dft(one/w,c);
    for(int i=0;i<n;i++) c[i]/=n;
    for(int i=0;i<n;i++) ret[i]=(fft_t)round(real(c[i]));
    //while(!ret.back()) ret.pop_back();
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    poly X(2*n),Y(2*n),Z(2*n);
    for(int i=0;i<n;i++){
        cin>>X[n-1-i];
        X[2*n-1-i]=X[n-1-i];
    }
    for(int i=0;i<n;i++){
        cin>>Y[i];
    }
    fft(X,Y,Z);
    cout<<*max_element(Z.begin()+n-1,Z.end())<<endl;
    return 0;
}