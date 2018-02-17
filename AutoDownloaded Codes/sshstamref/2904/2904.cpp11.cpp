#include <bits/stdc++.h>
using namespace std;
map<int,int> tot, fac[101];
int n, a[101];
int primes[1005]={2},np=1;
bool mark[1005];
void bp(){
    for(int i=3;i<1000;i+=2){
        if(!mark[i]){
            primes[np++]=i;
            for(int j=i*i;j<1000;j+=i) mark[j]=true;
        }
    }
}
void input_and_factorize(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<np;j++){
            while(a[i]%primes[j]==0){
                a[i]/=primes[j];
                ++fac[i][primes[j]];
                ++tot[primes[j]];
            }
        }
        ++fac[i][a[i]];
        ++tot[a[i]];
    }
}
void getans(){
    int g=1, mani=0;
    for(auto &f : tot){
        f.second/=n;
        for(int k=0;k<f.second;k++) g*=f.first;
    }
    printf("%d ",g);
    for(auto f : tot){
        for(int i=0;i<n;i++){
            if(fac[i][f.first]<f.second) mani+=f.second-fac[i][f.first];
        }
    }
    printf("%d\n",mani);
}
int main(){
    bp();
    input_and_factorize();
    getans();
}