#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef pair<int,pair<int,int>> ipii;
const int mx=1e4+5;
int rep[mx],v,e,s,k;
priority_queue<ipii> pq;
int f(int x){return x==rep[x]?x:rep[x]=f(rep[x]);}
void c(int x,int y){
    x=f(x),y=f(y);
    rep[y]=x;
}
void input(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    ipii t;
    cin>>v>>e;
    iota(rep+1,rep+v+1,1);
    for(int i=0;i<e;i++){
        cin>>t.vb.va>>t.vb.vb>>t.va;
        pq.push(t);
    }
    cin>>s>>k;
}
void pro(){
    int co;
    ipii t;
    do{
        t=pq.top(); pq.pop();
        co=t.va;
        c(t.vb.va,t.vb.vb);
    }while(f(s)!=f(k));
    printf("%d\n",co);
}
int main(){
    input();
    pro();
}