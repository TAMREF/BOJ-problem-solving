#include <bits/stdc++.h>
using namespace std;
vector<int> mt[270000];
int a[111111], N, M, x, y, z;
void build_tree(int node, int s, int e){
    if(s==e){
        mt[node]=vector<int>({a[s]});
        return;
    }
    build_tree(2*node,s,(s+e)/2);
    build_tree(2*node+1,(s+e)/2+1,e);
    mt[node] = vector<int>(mt[node*2].size()+mt[node*2+1].size());
    merge(mt[node*2].begin(),mt[node*2].end(),mt[node*2+1].begin(),mt[node*2+1].end(),mt[node].begin());
}
int underx(int node, int s, int e, int l, int r, int x){
    if(r<s || l>e) return 0;
    if(l<=s && e<=r) return (int)(lower_bound(mt[node].begin(),mt[node].end(),x)-mt[node].begin());
    return underx(2*node,s,(s+e)/2,l,r,x) + underx(2*node+1,(s+e)/2+1,e,l,r,x);
}
bool isthere(int node, int s, int e,int l, int r, int x){
    if(r<s || l>e) return false;
    if(l<=s && e<=r) return x==*lower_bound(mt[node].begin(),mt[node].end(),x);
    return isthere(2*node,s,(s+e)/2,l,r,x)||isthere(2*node+1,(s+e)/2+1,e,l,r,x);
}
int main(){
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++) scanf("%d",&a[i]);
    build_tree(1,1,N);
    sort(a+1,a+N+1);
    for(int i=0;i<M;i++){
        scanf("%d%d%d",&x,&y,&z);
        int L = 1, H = N, MID;
        while(L<=H){
            MID = (L+H)/2;
            int B = underx(1,1,N,x,y,a[MID]);
            if(B>=z) H=MID-1;
            else if(B<z-1)  L = MID+1;
            else {
            if(isthere(1,1,N,x,y,a[MID]))  break;
            else  L=MID+1;
            }
        }
        printf("%d\n",a[MID]);
    }
}
