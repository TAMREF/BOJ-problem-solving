#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int mx = 2005;

pii a[mx], b[mx];

int ca[mx], cb[mx];
int n, m;

pii col[mx * mx];
int numcol;

void input(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[2*i].first>>a[2*i+1].first;
        --a[2*i].first;
        a[2*i].second = 0;
        a[2*i+1].second = 1;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>b[2*i].first>>b[2*i+1].first;
        --b[2*i].first;
        b[2*i].second = 0;
        b[2*i+1].second = 1;
    }

    numcol = 4 * n * m;
    //assert(is_sorted(a,a+2*n) && is_sorted(b,b+2*m));
    sort(a,a+2*n);
    sort(b,b+2*m);

    for(int i=0;i<2*n;i++){
        for(int j=0;j<2*m;j++){
            col[2*m*i+j+1] = {a[i].first + b[j].first, a[i].second ^ b[j].second};
        }
    }

    sort(col+1,col + numcol+1);
}

ll greed(){
    ll v = 0, dv = 0, ans = 0, mv = 0;
    for(int i=1;i<=numcol;i++){
        v += dv * (col[i].first - col[i-1].first);
        //cout<<"now value = "<<v<<", pos = "<<col[i].first<<",dv = "<<dv<<endl;
        if(v > mv){
            //cout<<"now ans = "<<v<<' '<<col[i].first<<endl;
            mv = v;
            ans = col[i].first;
        }
        dv += (col[i].second?-1:1);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    cout<<greed()<<endl;
}
