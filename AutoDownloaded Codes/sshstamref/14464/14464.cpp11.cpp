#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef pair<int,int> ii;
struct cmp{
    bool operator()(ii u, ii v){return u.vb>v.vb;}
};
int chi[20005];
ii cow[20005];
int N,C;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>C>>N;
    for(int i=0;i<C;i++) cin>>chi[i];
    for(int i=0;i<N;i++) cin>>cow[i].first>>cow[i].second;
    sort(chi,chi+C);
    sort(cow,cow+N);
}
void greedy(){
    priority_queue<ii,vector<ii>,cmp> pQ;
    int match=0;
    for(int i=0,p=0;i<C;i++){
        for(;p<N && cow[p].va<=chi[i];++p) if(cow[p].vb>=chi[i]) pQ.push(cow[p]);
        while(!pQ.empty() && pQ.top().vb<chi[i]) pQ.pop();
        if(!pQ.empty()){
            pQ.pop();
            ++match;
        }
    }
    cout<<match<<'\n';
}
int main(){
    input();
    greedy();
}