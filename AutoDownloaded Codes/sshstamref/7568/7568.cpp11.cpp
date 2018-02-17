#include <bits/stdc++.h>
using namespace std;

pair<int,int> p[55];
int r[55];
int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>p[i].first>>p[i].second;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(p[i].first<p[j].first && p[i].second<p[j].second) ++r[i];
        }
    }
    for(int i=0;i<n;i++) printf("%d%c",r[i]+1,"\n "[i<n-1]);
}