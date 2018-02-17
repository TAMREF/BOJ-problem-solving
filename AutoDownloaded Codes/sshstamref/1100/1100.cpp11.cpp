#include <bits/stdc++.h>
using namespace std;
int main(){
    char k; int cnt = 0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            k = getchar();
            if(k == 'F' && ((i^j)&1) == 0){
                ++cnt;
            }
        }
        getchar();
    }
    printf("%d\n",cnt);
}