#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int inf = 3e8;
int C[3005][6005], E[3005][6005];
deque<pii> D[3005];

int n, m, s, e, t;
int psum[3005][6005];
int fb[3005];

void input(){
    cin >> n >> m >> s >> e >> t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> psum[i][j];
            psum[i][j] += psum[i][j-1];
        }
        for(int j = m + 1; j < m + s; j++) psum[i][j] = psum[i][j-1];
    }
    for(int i=1;i<=n;i++){
        cin >> fb[i];
    }
}

inline void trim(deque<pii>& d, int second_th){
    while(!d.empty() && d.front().second < second_th) d.pop_front();
}

inline void pback(deque<pii>& d, pii v){
    while(!d.empty() && d.back() >= v) d.pop_back();
    d.push_back(v);
}

void pass(pii &n1, pii &n2, pii &n3, pii v){
    if(n1 >= v){
        n3 = n2; n2 = n1; n1 = v;
    }else if(n2 >= v){
        n3 = n2; n2 = v;
    }else if(n3 >= v){
        n3 = v;
    }
}

void dp(){
    for(int i=1;i<=n;i++){
        for(int j = 1; j < s; j++){
            C[i][j] = psum[i][j];
        }
    }
    for(int j = s; j < m + s; j++){
        pii m[3] = {{INT_MAX,-1}, {INT_MAX,-1}, {INT_MAX,-1}};
        for(int i = 1; i <= n; i++){
            trim(D[i], j-e);
            if(j - s >= s) pback(D[i], {E[i][j-s],j-s});

            C[i][j] = inf;
            if(!D[i].empty()) C[i][j] = min(C[i][j], D[i].front().first + psum[i][j] + t);
            if(j <= e) C[i][j] = min(C[i][j], psum[i][j]);

            pass(m[0],m[1],m[2],{C[i][j],i});
        }
        for(int i = 1; i <= n; i++){
            for(int b = 0; b < 3; b++){
                if(m[b].second != i && m[b].second != fb[i]){
                    E[i][j] = m[b].first - psum[i][j];
                    break;
                }
            }
        }
    }
    int ans = INT_MAX;
    for(int i=1;i<=n;i++){
        ans = min(ans, *min_element(C[i] + m, C[i] + m + s));
    }
    cout << ans << endl;
}

void debug(){
    puts("C");
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < m + s; j++){
            printf("%3d ",C[i][j]);
        }
        puts("");
    }
    puts("E");
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < m + s; j++){
            printf("%3d ",E[i][j]);
        }
        puts("");
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("sample.txt","rt",stdin);
    input();
    dp();
    //debug();
}
