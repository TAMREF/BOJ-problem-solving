#include <bits/stdc++.h>
#define bp __builtin_popcount
using namespace std;
inline int tp(int x){
    int cnt=0;
    for(;x;x/=3) cnt+=(x%3==1);
    return cnt;
}
vector<int> G[20];
int N, a[20];
long long tsp[20][1048576];
void init(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(bp(a[i])==bp(a[j])||tp(a[i])==tp(a[j])){
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }
    for(int i=0;i<N;i++){
        tsp[i][1<<i]=1;
    }
}
void travel(){
    for(int b=1;b<(1<<N)-1;b++){
        for(int i=0;i<N;i++){
            for(int j : G[i]){
                if((b & 1<<j) ==0){
                    tsp[j][b|(1<<j)]+=tsp[i][b];
                }
            }
        }
    }
}
void debug(){
    for(int i=0;i<N;i++,puts("")) for(int u : G[i]) printf("%d ",u);
    for(int i=0;i<N;i++,puts("")) for(int j=0;j<(1<<N);j++) printf("%d ",tsp[i][j]);
}
int main(){
    init();
    travel();
    long long perm=0;
    for(int i=0;i<N;i++) perm+=tsp[i][(1<<N)-1];
    printf("%lld\n",perm);
    //debug();
}