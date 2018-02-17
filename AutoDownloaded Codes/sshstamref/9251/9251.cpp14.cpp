#include <bits/stdc++.h>
using namespace std;
int D[2][4005], len1, len2;
char tam1[4005], tam2[4005];
void input(){
    fgets(tam1,4005,stdin);
    fgets(tam2,4005,stdin);
    len1 = strlen(tam1)-1;
    len2 = strlen(tam2)-1;
    tam1[len1]=tam2[len2]='\0';
}
int len_LCS_naive(char* x, char* y, int sx, int sy){
    for(int i=1;i<=sx;i++){
        for(int j=1;j<=sy;j++){
            if(x[i-1]==y[j-1]) D[i][j]=D[i-1][j-1]+1;
            else D[i][j] = max(D[i-1][j],D[i][j-1]);
        }
        //printf("DEBUG STEP %d\n",i); for(int j=1;j<=len2;j++) printf("D[%d][%d]=%d\n",i,j,D[i&1][j]);
    }
    return D[sx][sy];
}
int len_LCS(char* x, char* y, int sx, int sy){
    for(int i=1;i<=sx;i++){
        for(int j=1;j<=sy;j++){
            if(x[i-1]==y[j-1]) D[i&1][j]=D[1-(i&1)][j-1]+1;
            else D[i&1][j] = max(D[1-(i&1)][j],D[i&1][j-1]);
        }
        //printf("DEBUG STEP %d\n",i); for(int j=1;j<=len2;j++) printf("D[%d][%d]=%d\n",i,j,D[i&1][j]);
    }
    return D[sx&1][sy];
}
void debug(){
    puts(tam1);
    puts(tam2);
}
int main(){
    //freopen("input.txt","rt",stdin);
    input();
    return 0*printf("%d\n",len_LCS(tam1,tam2,len1,len2));
}
