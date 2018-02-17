#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef pair<int,int> ii;
const int mx = 100005;
vector<ii> G[mx];
int gnum;
int vis[mx], s[mx], t[mx], pnt[mx], fd[mx], des[mx], radi[mx], U[mx], pc[mx];
ii dfs(int x){
    vis[x]=1; des[x]=x;
    ii z(0,x), w;
    for(ii &u : G[x]){
        if(u.va == pnt[x]) continue;
        pnt[u.va]=x;  pc[u.va]=u.vb;
        w=dfs(u.va); w={w.va+u.vb,w.vb};
        if(z<w){
            z=w;
            des[x]=u.va;
        }
    }
    fd[x]=z.vb;
    return z;
}
static int radius(int s, int t, int r){
    int R=r, S=0;
    for(int now=des[s];S<r;now=des[now]){
        S+=pc[now];
        R=min(R,max(S,r-S));
    }
    return R;
}
int travelTime(int N, int M, int L, int A[], int B[], int T[]) {
    ii z;
    for(int i=0;i<M;i++){
        G[A[i]].push_back({B[i],T[i]});
        G[B[i]].push_back({A[i],T[i]});
    }
    for(int i=0;i<N;i++){
        if(!vis[i]){
            pnt[i]=-1;
            s[gnum]=dfs(i).second;
            pnt[s[gnum]]=-1;
            tie(radi[gnum],t[gnum])=dfs(s[gnum]);
            U[gnum]=radius(s[gnum],t[gnum],radi[gnum]);
            ++gnum;
        }
    }
    int ans = *max_element(radi,radi+gnum);
    sort(U,U+gnum);
    for(int s=gnum;s>1;s--){
        ans=max(ans,U[s-2]+L+U[s-1]);
        U[s-2]=max(U[s-2]+L,U[s-1]);
    }
    return ans;
}
static int A[mx];
static int B[mx];
static int T[mx];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int N, M, L, i;
	cin>>N>>M>>L;
	for (i = 0; i < M; i++) cin>>A[i]>>B[i]>>T[i];
	int answer = travelTime(N, M, L, A, B, T);
	cout<<answer<<endl;
	return 0;
}