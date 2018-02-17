#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> Pi;
const int MX=100005;
priority_queue<Pi,vector<Pi>,greater<Pi>> Q;
int N, S, M, F, T[MX];
int main(){
    cin.sync_with_stdio(false);
    cin>>N>>S>>M;
    for(int i=1;i<=M;i++){
        cin>>T[i];
        Q.push(make_pair(0LL,i));
    }
    for(int i=0;i<N-S;i++){
        F=Q.top().second;
        Q.push(make_pair(Q.top().first+T[F],F));
        Q.pop();
    }
    cout<<F<<endl;
}
