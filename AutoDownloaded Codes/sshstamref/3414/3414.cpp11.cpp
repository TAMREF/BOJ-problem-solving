#include <bits/stdc++.h>

using namespace std;

const int mx = 100000;

vector<int> C[mx];

int ideg[2][mx], ty[mx];
int V, E;

queue<int> Q[2][2];

void init(){
    for(int i=0;i<V;i++) C[i].clear();

    cin>>V>>E;
    for(int i=0;i<V;i++){
        cin>>ty[i];
        --ty[i];
    }
    for(int a,b,k=0;k<E;k++){
        cin>>a>>b;
        C[a-1].push_back(b-1);
        ++ideg[0][b-1];
        ++ideg[1][b-1];
    }
}

void greed(){
    int cnt[2] = {}, tog = 0;

    for(int i = 0 ; i < V ; i++){
        if(!ideg[0][i]){
            Q[0][ ty[i] ].push( i );
            Q[1][ ty[i] ].push( i );
        }
    }

    for(int c = 0 ; c < 2 ; c++ ){
        tog = c;
        for(; !Q[c][tog].empty() || !Q[c][!tog].empty() ; cnt[c]++, tog ^= 1){
            while(!Q[c][tog].empty()){
                int z = Q[c][tog].front(); Q[c][tog].pop();
                for( int &u : C[z] ){
                    --ideg[c][u];
                    if(ideg[c][u] == 0){
                        Q[c][ ty[u] ].push( u );
                    }
                }
            }
        }
    }
    cout<<min(cnt[0],cnt[1])-1<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    for(int tc = 0;tc<t;tc++){
        init();
        greed();
    }
    return 0;
}
