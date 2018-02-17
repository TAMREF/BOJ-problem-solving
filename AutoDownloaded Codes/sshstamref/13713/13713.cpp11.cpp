#include <bits/stdc++.h>
using namespace std;
const int mx=1e6+5;
string S;
int Z[mx];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    getline(cin,S);
    int n=S.size();
    reverse(S.begin(),S.end());
    //cout<<S<<'\n';
    //printf("n=%d\n",n);
    assert(S[n-1]!=10);
    for(int i=1,l=0,r=0;i<n;i++){
        if(i<=r){
            if(i+Z[i-l]<r) Z[i]=Z[i-l];
            else{
                l=i;
                for(;r<n && S[r] == S[r-l];r++);
                Z[i] = (r--)-l;
            }
        }else{
            l=r=i;
            for(;r<n && S[r]==S[r-l];r++);
            Z[i] = (r--)-l;
        }
    }
    Z[0]=n;
    //for(int i=0;i<n;i++) printf("%d ",Z[i]); puts("");
    int q,v;
    for(cin>>q;q--;){
        cin>>v;
        cout<<Z[n-v]<<'\n';
    }
}