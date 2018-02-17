#include <bits/stdc++.h>
using namespace std;
using ii=pair<int,int>;
ii tam[50];
int y[50];
int main(){
    int n,i=0,x;
    for(cin>>n;i<n;i++){
        cin>>x;
        tam[i]={x,i};
    }
    sort(tam,tam+n);
    for(i=0;i<n;i++) y[tam[i].second]=i;
    for(i=0;i<n;i++) cout<<y[i]<<" \n"[i==n-1];
}