#include <bits/stdc++.h>
using namespace std;
inline int mx(int u, int v){return u>v?u:v;}
struct Indexedtree{
    int tree[262145];
    Indexedtree(){memset(tree,0,sizeof(tree));}
    void update(int pos,int val){
        pos+=131072;
        tree[pos]+=val;
        for(;pos>>1;pos>>=1)
            tree[pos>>1]=mx(tree[pos^1],tree[pos]);
    }
};
/*
struct Segtree{
    int N, dat[100005], seg[262145];
    int rmq_l, rmq_r;
    int upd_pos, upd_inc;
    Segtree(int N):N(N){
        memset(dat,0,sizeof(dat));
        memset(seg,0,sizeof(seg));
    }
    Segtree(int N, int* data):N(N){
        memset(seg,0,sizeof(seg));
        copy(data,data+N,dat);
    }
    int init(int now, int s, int e){
        if(s==e) return seg[now]=dat[s];
        int m=(s+e)>>1;
        return seg[now]=max(init(now<<1,s,m),init(now<<1|1,m+1,e));
    }
    int do_rmq(int now, int s, int e){
        if(rmq_r<s||e<rmq_l) return 0;
        if(s<=rmq_l && rmq_r <=e) return seg[now];
        int m=(s+e)>>1;
        return mx(do_rmq(now<<1,s,m),do_rmq(now<<1|1,m+1,e));
    }
    int rmq(int l=0, int r=100002){
        rmq_l=l, rmq_r=r;
        return do_rmq(1,0,N-1);
    }
    void do_update(int now, int s, int e){
        if(upd_pos<s||e<upd_pos) return;
        if(s!=e){
            int m=(s+e)>>1;
            do_update(now<<1,s,m);
            do_update(now<<1|1,m+1,e);
            seg[now]=mx(seg[now<<1],seg[now<<1|1]);
        } else{
            seg[now]=dat[s]=(dat[s]+upd_inc);
        }
    }
    void update(int pos, int inc){
        upd_pos=pos, upd_inc=inc;
        do_update(1,0,N-1);
    }
};
*/
struct Qr{
    int idx,s,e;
};

int N,Q,buk;
int dat[100005],ans[100005];
Qr my[100005];
//Segtree S(100005);
Indexedtree I;
void input(){
    cin>>N;
    for(int i=1;i<=N;i++) scanf("%d",&dat[i]);
    cin>>Q;
    buk=max(10,(int)((double)N/sqrt(Q)));
    for(int i=0;i<Q;i++){
        my[i].idx=i;
        scanf("%d%d",&my[i].s,&my[i].e);
    }
    sort(my,my+Q,[buk](Qr u, Qr v)->bool{
            return u.s/buk==v.s/buk?u.e<v.e:u.s<v.s;
         });
}

void MO(){
    for(int q=0,cans=0,l=1,r=0;q<Q;q++){
        for(;r<my[q].e;){
            I.update(dat[++r],1);
        }
        for(;r>my[q].e;){
            I.update(dat[r--],-1);
        }
        for(;l<my[q].s;){
            I.update(dat[l++],-1);
        }
        for(;l>my[q].s;){
            I.update(dat[--l],1);
        }
        ans[my[q].idx]=I.tree[1];
    }
}

void output(){
    for(int i=0;i<Q;i++) printf("%d\n",ans[i]);
}

int main(){
    //freopen("input.txt","rt",stdin);
    //clock_t u=clock();
    input();
    MO();
    //printf("%d\n",clock()-u);
    output();
}