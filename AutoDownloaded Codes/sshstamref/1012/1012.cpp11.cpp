#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int board[55][55], vis[55][55];
int n,m,k;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
void input(){
    cin>>n>>m>>k;
    memset(board,0,sizeof(board));
    memset(vis,0,sizeof(vis));
    for(int i=0,r,c;i<k;i++){
        cin>>r>>c;
        board[r+1][c+1] = 1;
    }
}

int bfs(){
    int comp = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!vis[i][j] && board[i][j]){
                ++comp;
                queue<pii> q;
                q.push({i,j});
                vis[i][j] = 1;
                while(!q.empty()){
                    pii z = q.front(); q.pop();
                    for(int t=0;t<4;t++){
                        if(!vis[z.first+dx[t]][z.second+dy[t]] && board[z.first+dx[t]][z.second+dy[t]]){
                            q.push({z.first+dx[t],z.second+dy[t]});
                            vis[z.first+dx[t]][z.second+dy[t]] = 1;
                        }
                    }
                }
            }
        }
    }
    return comp;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    for(cin>>t;t--;){
        input();
        cout<<bfs()<<'\n';
    }
}