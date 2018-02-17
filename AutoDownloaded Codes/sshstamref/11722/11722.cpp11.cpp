#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> LDS;
int x, N;
int main(){
    for(scanf("%d",&N);N--;){
        scanf("%d",&x);
        if(LDS.empty() || x<LDS.back()) LDS.push_back(x);
        else *lower_bound(LDS.begin(),LDS.end(),x,greater<int>())=x;
    }
    printf("%d\n",LDS.size());
    return 0;
}