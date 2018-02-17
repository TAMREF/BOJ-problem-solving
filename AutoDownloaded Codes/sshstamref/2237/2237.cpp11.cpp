#include <bits/stdc++.h>
using namespace std;
unordered_map<int,short> m[102];
short s[102];
int n,t,a[102];
void input(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>t;
    for(int i=0;i<n;i++) cin>>a[i];
}
void pro(){
    m[0][a[0]]=1;
    m[1][a[0]-a[1]]=-1;
    for(int i=2;i<n;i++){
        for(auto p : m[i-1]){
            m[i][p.first+a[i]]=1;
            m[i][p.first-a[i]]=-1;
        }
    }
    int mnus=0, now=t;
    for(int i=n-1;i>=0;--i){
        s[i]=m[i][now];
        now-=a[i]*m[i][now];
    }
    //for(int i=0;i<n;i++) printf("%d ",s[i]); puts("");
}
void output(){
    stack<int> sp;
    int currm=1;
    for(int i=1;i<n;i++){
        if(s[i]==1) sp.push(currm);
        else currm=i;
    }
    n-=sp.size();
    for(;!sp.empty();sp.pop()){
        printf("%d\n",sp.top()+1);
    }
    for(;--n;) puts("1");
}
int main(){
    input();
    pro();
    output();
}