#include <bits/stdc++.h>
using namespace std;
int fi[15]={0,0,0,0,0,1,1,1,1,2,2,2,3,3,4};
int se[15]={1,2,3,4,5,2,3,4,5,3,4,5,4,5,5};
int ans[4], res[4][6][3], tmp[4][6][3];
int tc;
bool cmp(){
    for(int i=0;i<6;i++) for(int j=0;j<3;j++) if(res[tc][i][j]!=tmp[tc][i][j]) return false;
    return true;
}
void ngd(int j){
    if(ans[tc]) return;
    if(j==15){
        if(cmp()) ans[tc]=1;
        return;
    }
    for(int k=0;k<3;k++){
        if(tmp[tc][fi[j]][k]==res[tc][fi[j]][k] || tmp[tc][se[j]][2-k]==res[tc][se[j]][2-k]) continue;
        ++tmp[tc][fi[j]][k], ++tmp[tc][se[j]][2-k];
        ngd(j+1);
        --tmp[tc][fi[j]][k], --tmp[tc][se[j]][2-k];
    }
}
int main(){
    for(int i=0;i<4;i++){
        for(int j=0;j<6;j++){
            for(int k=0;k<3;k++){
                scanf("%d",&res[i][j][k]);
            }
        }
    }
    for(tc=0;tc<4;tc++) ngd(0);
    for(int i=0;i<4;i++) printf("%d ",ans[i]);
}
