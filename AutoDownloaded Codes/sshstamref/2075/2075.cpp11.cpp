#include <bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int>> Q;
int main(){
    int N;
    scanf("%d",&N);
    for(int i=0,x;i<N;i++){
        scanf("%d",&x);
        Q.push(x);
    }
    for(int i=1,x,t;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&x);
            t=Q.top(); Q.pop();
            Q.push(max(t,x));
        }
    }
    return !printf("%d\n",Q.top());
}