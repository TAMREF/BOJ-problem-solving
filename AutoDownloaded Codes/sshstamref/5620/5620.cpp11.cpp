#include <bits/stdc++.h>
#define vx first
#define vy second

using namespace std;

typedef pair<int,int> pii;

const int mx = 500005;

inline int sq(int k){
    return k * k;
}

inline int d(pii u, pii v){
    return sq(u.vx - v.vx) +sq(u.vy - v.vy);
}

inline bool cmpy(pii u, pii v){
    return u.vy<v.vy;
}

pii xSort[mx], ySort[mx], tmp[mx];

vector<pii> Candi;

int closest(int s, int e){
    if( s == e ) return 1e9;

    int m = (s+e)>>1,
        dnow = min( closest(s,m), closest(m+1,e) );

    merge(ySort+s, ySort+m+1,  ySort+m+1, ySort+e+1,  tmp+s,
          cmpy);

    copy(tmp+s, tmp+e+1,  ySort+s);

    Candi.clear();

    for(int i=s;i<=e;i++){
        if( d(xSort[m] , ySort[i]) < dnow )
            Candi.push_back(ySort[i]);
    }

    for(int i=Candi.size(); i-- ;){
        for(int j = i ; j-- ; ){
            if( sq(Candi[j].vy - Candi[i].vy) >= dnow ) break;
            dnow = min(dnow, d(Candi[i], Candi[j]));
        }
    }

    return dnow;
}

int main(){
    int n;
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    Candi.reserve(n);
    for(int i=0;i<n;i++){
        cin>>xSort[i].vx>>xSort[i].vy;
    }
    sort(xSort,xSort+n);
    copy(xSort,xSort+n, ySort);
    cout<<closest(0,n-1)<<endl;
}