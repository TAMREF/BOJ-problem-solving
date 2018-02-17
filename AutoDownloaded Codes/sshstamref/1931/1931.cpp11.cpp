#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
pii a[100005];
vector<pii> tam;
int main(){
    int N; scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d%d",&a[i].second,&a[i].first);
    sort(a,a+N);
    tam.push_back(a[0]);
    for(int i=1;i<N;i++){
        if(a[i].second>=tam.back().first) tam.push_back(a[i]);
    }
    printf("%d\n",tam.size());
}
