#include <bits/stdc++.h>
using namespace std;
const int MX=131072;
int a[MX], seg[2*MX];
inline int sgn(int x){return x>0?1:x<0?-1:0;}
int build(int now, int s, int e){
    if(s==e) return seg[now]=sgn(a[s]);
    int m=(s+e)>>1;
    return seg[now]=build(now<<1,s,m)*build(now<<1|1,m+1,e);
}
int val(int now, int s, int e, int l, int r){
    if(r<s||l>e) return 1;
    if(l<=s&&e<=r) return seg[now];
    int m=(s+e)>>1;
    return val(now<<1,s,m,l,r)*val(now<<1|1,m+1,e,l,r);
}
void update(int now, int s, int e, int k, int v){
    if(k<s||k>e) return;
    if(s==e){
        seg[now]=v;
        return;
    } int m=(s+e)>>1;
    update(now<<1,s,m,k,v); update(now<<1|1,m+1,e,k,v);
    seg[now]=seg[now<<1]*seg[now<<1|1];
}
int main(){
    for(int N,M,x,y,z,w;scanf("%d %d",&N,&M)==2;){
        for(int i=0;i<N;i++) scanf("%d",&a[i]);
        build(1,0,N-1);
        getchar();
        for(char c;M--;){
            scanf("%c %d %d",&c,&x,&y);
            if(c=='P'){
                z=val(1,0,N-1,x-1,y-1);
                putchar(z>0?'+':z?'-':'0');
            }else{
                w=y, y=sgn(y), z=sgn(a[x-1]),a[x-1]=w;
                if(z==y) goto ctn;
                update(1,0,N-1,x-1,y);
            }
            ctn:
            getchar();
        } puts("");
    }
}
