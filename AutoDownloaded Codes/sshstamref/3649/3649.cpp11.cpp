#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<int> P;
int t, n, x, y;
int main(){
    P.reserve(1<<20);
    for(int flag;scanf("%d",&x)==1;){
        flag = 0;
        if(x<=20){
            P.clear();
            x *= 10000000;
            scanf("%d",&n);
            for(int i=0;i<n;i++){
                scanf("%d",&y);
                P.push_back(y);
            }
            sort(P.begin(),P.end());
            for(auto p=P.begin();*p <= x && p!=P.end();p++){
                auto it = lower_bound(P.begin(),P.end(),x-*p);
                if( it == P.end() || *it + *p != x) continue;
                if( it != p || it!=P.end() && (it+1) != P.end() && *p == *(it+1) ){
                    printf("yes %d %d\n",*p,*it);
                    flag = 1;
                    break;
                }
            }
        }
        if(!flag) puts("danger");
    }
}