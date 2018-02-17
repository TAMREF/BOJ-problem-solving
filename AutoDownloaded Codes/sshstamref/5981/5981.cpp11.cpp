#include <cstdio>
#include <algorithm>
using namespace std;
const double phi=1.6180339887498948482045868343656;
int t;
int main(){
    scanf("%*d%*d%d",&t);
    while(t--){
        int x,y;
        scanf("%d%d",&x,&y);
        if(x>y) swap(x,y);
        puts((int)((y-x)*phi)==x ? "Farmer John" : "Bessie");
    }
    return 0;
}