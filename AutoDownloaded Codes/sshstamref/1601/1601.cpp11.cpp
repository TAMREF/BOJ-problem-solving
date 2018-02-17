#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int inf = 1e8;
map<pii,pii> m;

inline int sgn(int x){
    return x>0?1:-1;
}

int dfs(int x, int y, int msb){
    if(x==0 && y==0) return 0;
    if(msb < 0){
        return inf;
    }
    if(x==0 || y==0) return inf;
    if(abs(x) >= 1<<(msb+1) || abs(y) >= 1<<(msb+1)) return inf;
    int nx = x - sgn(x) * (1<<msb), ny = y - sgn(y) * (1<<msb);
    int j1 = dfs(nx,ny,msb-1) + 1;
    int j2 = dfs(x,y,msb-1);
    if(j1 < j2){
        m[{x,y}]={nx,ny};
    }
    return min(j1,j2);
}

int main(){
    int x,y;
    cin>>x>>y;
    if(x==0 && y==0){
        puts("1\n0,0");
        return 0;
    }
    if((x^y)&1){
        puts("-1");
        return 0;
    }
    int ans = dfs(x,y,27);
    if(ans == inf){
        puts("-1");
        return 0;
    }
    vector<pii> track;
    pii p = {x,y};
    while(p != make_pair(0,0)){
        track.push_back(p);
        p = m[p];
    }
    track.push_back({0,0});
    cout << track.size() << '\n';
    for(int i=track.size();i--;){
        cout << track[i].first <<","<<track[i].second<<'\n';
    }
    return 0;
}
