#include <bits/stdc++.h>
using namespace std;
//attempt 1. segment tree - recursion
//attempt 2. segment tree - repetition
//attempt 3. fenwick tree
//attempt 4. hanpil's table
const int LIM = 270000;
int seg[LIM], a[100005], N,M, i, x, y;
void input(){
    scanf("%d%d",&N,&M);
    for(i=0;i<N;i++) scanf("%d",&a[i]);
}
int seg1(int node, int s, int e){
    if(s==e) return seg[node] = a[s];
    return seg[node] = min(seg1(2*node,s,(s+e)/2),seg1(2*node+1,(s+e)/2+1,e));
}
int seg1_find(int node, int s, int e, int l, int r){
    if(e<l || s>r) return 2147483647;
    if(l<=s&&e<=r) return seg[node];
    return min(seg1_find(2*node,s,(s+e)/2,l,r),seg1_find(2*node+1,(s+e)/2+1,e,l,r));
}
int main(){
    //freopen("input.txt","rt",stdin);
    input();
    seg1(1,0,N-1);
    while(M--){
        scanf("%d%d",&x,&y);
        printf("%d\n",seg1_find(1,0,N-1,x-1,y-1));
    }
}