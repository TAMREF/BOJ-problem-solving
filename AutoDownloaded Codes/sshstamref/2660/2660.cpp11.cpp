#include <bits/stdc++.h>
using namespace std;
int D[55][55],i,j,k;
pair<int,int> t[55];
int main(){
    int N, c=1;
    cin>>N;
    for(i=1;i<=N;D[i][i]=0,i++) fill(D[i]+1,D[i]+N+1,99);
    for(int a,b;;){
        scanf("%d%d",&a,&b);
        if(a<0) break;
        D[a][b]=D[b][a]=1;
    }
    for(k=1;k<=N;k++) for(i=1;i<=N;i++) for(j=1;j<=N;j++) D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
    for(int i=1;i<=N;i++)t[i]=make_pair(*max_element(D[i]+1,D[i]+N+1),i);
    sort(t+1,t+N+1);
    while(t[c].first==t[1].first) ++c;
    printf("%d %d\n",t[1].first,c-1);
    for(int i=1;i<c;i++) printf("%d ",t[i].second);
}
