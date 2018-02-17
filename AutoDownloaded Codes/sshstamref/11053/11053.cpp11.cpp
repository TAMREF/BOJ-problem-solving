//LIS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> LIS;
int x, N;
int main(){
    for(scanf("%d",&N);N--;){
        scanf("%d",&x);
        if(LIS.empty() || x>LIS.back()) LIS.push_back(x);
        else *lower_bound(LIS.begin(),LIS.end(),x)=x;
    }
    printf("%d\n",LIS.size());
    return 0;
}
