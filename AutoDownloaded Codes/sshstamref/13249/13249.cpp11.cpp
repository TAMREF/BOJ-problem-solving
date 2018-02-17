#include <bits/stdc++.h>
#define G (1<<N)
using namespace std;
int x[15];
vector<int> r, l;
int main(){
    int N, T;
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&x[i]);
    scanf("%d",&T);
    long long c=0;
    for(int bit=0;bit<G;bit++){
        r.clear(); l.clear();
        for(int i=0;i<N;i++) (bit&1<<i?r:l).push_back(x[i]);
        sort(r.begin(),r.end()); sort(l.begin(),l.end());
        for(int u : r){
            c+=upper_bound(l.begin(),l.end(),u+2*T)-lower_bound(l.begin(),l.end(),u);
        }
    }
    printf("%.10f\n",(double)c/G);
}
