#include <bits/stdc++.h>
using namespace std;
int diff(char* u, char* v, int len){
    int cnt=0;
    for(int i=0;i<len;i++) cnt+=(u[i]!=v[i]);
    return cnt;
}
int main(){
    char A[55], B[55];
    scanf("%s %s",A,B);
    int lea = strlen(A), leb = strlen(B), di=lea;
    for(int i=0;i<=leb-lea;i++) di = min(di,diff(A,B+i,lea));
    printf("%d\n",di);
}