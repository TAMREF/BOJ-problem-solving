#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
unsigned int sp[404][404];
vector<ii> G[404];
int v,e,p,q,r;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>v;
    for(int i=1;i<=v;i++) fill(sp[i]+1,sp[i]+v+1,INT_MAX);
    for(cin>>e;e--;){
        cin>>p>>q>>r;
        sp[p][q]=min(sp[p][q],(unsigned int)r);
    }
}
void floyd(){
    for(int k=1;k<=v;k++){
        for(int i=1;i<=v;i++){
            for(int j=1;j<=v;j++){
                sp[i][j]=min(sp[i][j],sp[i][k]+sp[k][j]);
            }
        }
    }
}
void cyc(){
    unsigned int C=UINT_MAX;
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            C=min(C,sp[i][i]);
        }
    }
    printf("%d\n",C<1e5?(int)C:-1);
}
int main(){
    input();
    floyd();
    cyc();
}