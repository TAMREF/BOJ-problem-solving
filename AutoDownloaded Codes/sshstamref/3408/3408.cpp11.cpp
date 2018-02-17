#include <bits/stdc++.h>
using namespace std;

const int mx = 200005;

int pr[mx], nx[mx], a[mx];
int n, m, t;

bool dnc(int s, int e){
    if(s==e) return false;
    for(int i=0, mid; i < (e-s) ; i++){
        mid = ( i & 1? s + i/2 : e-1-i/2);
        if(pr[mid] < s && nx[mid] >= e){
            return dnc(s,mid)||dnc(mid+1,e);
        }
    }
    return true;
}

unordered_map<int,int> las;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(cin>>t; t--;){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        las.clear();
        for(int i=0;i<n;i++){
            pr[i] = las[a[i]]-1;
            las[a[i]] = i+1;
        }
        
        las.clear();
        for(int i=n;i--;){
            nx[i] = las[a[i]]+n;
            las[a[i]] = i-n;
        }

        cout << (dnc(0,n)?"boring":"non-boring") << '\n';
    }
}