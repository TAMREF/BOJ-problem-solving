#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int clnum = 5060;

struct pt{
    ll x,y;
};

struct line{
    ll A,B,C;
    bool upper(pt &z){
        return A * z.x + B * z.y + C > 0;
    }
};

bool cross(line u, line v){
    return u.A * v.B != u.B * v.A;
}

vector<int> G[clnum];

pt kni[50005];

line riv[105];

vector<int> Idle;
vector<int> nTop, tnTop;

int n,m;

int planar_partition(){
    int tot = 1;
    for(int i=0;i<n;i++){
        int cnt = 1;
        for(int j=0;j<i;j++){
            if(cross(riv[i], riv[j])) ++cnt;
        }
        tot += cnt;
    }
    //printf("planar_partition = %d\n",tot);
    return tot;
}


void init(){
    Idle.clear();
    nTop.clear();
    for(int i=0;i<clnum;i++) G[i].clear();

    for(int i=0;i<clnum;i++) Idle.push_back(i);

    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>riv[i].A>>riv[i].B>>riv[i].C;
    }

    for(int i=0;i<m;i++){
        cin>>kni[i].x>>kni[i].y;
    }
}

int pro(){
    int top, l, r;
    top = Idle.back(); Idle.pop_back();
    for(int i=0;i<m;i++) G[top].push_back(i);
    nTop.push_back(top);

    for(int i=0;i<n;i++){
        while(!nTop.empty()){
            top = nTop.back(); nTop.pop_back();
            l = Idle.back(); Idle.pop_back();
            r = Idle.back(); Idle.pop_back();
            for(int &u : G[top]){
                G[(riv[i].upper(kni[u])?l:r)].push_back(u);
            }

            G[top].clear();
            Idle.push_back(top);

            (G[l].empty()?Idle:tnTop).push_back(l);
            (G[r].empty()?Idle:tnTop).push_back(r);
        }

        nTop.resize(tnTop.size());

        copy(tnTop.begin(), tnTop.end(), nTop.begin());

        tnTop.clear();
    }
    return nTop.size();
}

int main(){
    Idle.reserve(clnum+1);
    nTop.reserve(clnum+1);
    tnTop.reserve(clnum+1);
    G[clnum-1].reserve(50005);

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,p;
    for(cin>>t;t--;){
        init();
        p = pro();
        cout<<(p==planar_partition()?"PROTECTED":"VULNERABLE")<<'\n';
    }
}
