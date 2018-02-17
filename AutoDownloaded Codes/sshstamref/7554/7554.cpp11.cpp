#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T,N,a[1000],I; cin>>T;
    for(int f=1;f<=T;f++){
        cin>>N;
        I = 0;
        for(int i=0;i<N;i++) cin>>a[i];
        for(int i=0;i<N;i++) for(int j=i+1;j<N;j++) if(a[i]>a[j]) ++I;
        cout<<"Scenario #"<<f<<":\n"<<I<<"\n\n";
    }
    return 0;
}