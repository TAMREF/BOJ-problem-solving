#include <bits/stdc++.h>
using namespace std;
const int mx=1003;
char buf[mx][mx];
long long uc[2][mx][mx], lc[2][mx][mx], luc[2][mx+mx], us[2][mx][mx], ls[2][mx][mx], lus[2][mx+mx];
int r, c, n;
void input(){
    scanf("%d%d",&r,&c);
    n=max(r,c)+2;
    for(int i=0;i<r;i++){
        scanf("%*c%s",buf[i]);
        for(int j=0;j<c;j++) buf[i][j]=(buf[i][j]=='S'?1:(buf[i][j]=='M'?0:-1));
    }
}
void pro(){
    long long ans[2]={0,0};
    long long ldc[mx], ruc[mx], lds[mx], rus[mx];
    for(int ch=0;ch<2;ch++){
        for(int i,j,s=0;s<r+c-1;s++){
            for(int k=max(0,s-r+1),b=min(s,c-1),j=k;j<=b;j++){
                lds[j]=(j>k?lds[j-1]+ldc[j-1]:0);
                ldc[j]=(j>k?ldc[j-1]:0)+(buf[s-j][j]==ch);
            }
            for(int k=min(s,c-1),b=max(0,s-r+1),j=k;j>=b;j--){
                rus[j]=(j<k?rus[j+1]+ruc[j+1]:0);
                ruc[j]=(j<k?ruc[j+1]:0)+(buf[s-j][j]==ch);
            }
            for(int j=max(0,s-r+1),b=min(s,c-1);j<=b;j++){
                i=s-j;
                uc[ch][i][j]=(i?uc[ch][i-1][j]:0)+luc[ch][i-j+n]+ruc[j];
                lc[ch][i][j]=(j?lc[ch][i][j-1]:0)+luc[ch][i-j+n]+ldc[j];
                lus[ch][i-j+n]+=luc[ch][i-j+n];
                us[ch][i][j]=(i?us[ch][i-1][j]+uc[ch][i-1][j]:0)+lus[ch][i-j+n]+rus[j];
                ls[ch][i][j]=(j?ls[ch][i][j-1]+lc[ch][i][j-1]:0)+lus[ch][i-j+n]+lds[j];
                luc[ch][i-j+n]+=(buf[i][j]==ch);
                if(buf[i][j]==ch) ans[ch]+=us[ch][i][j]+ls[ch][i][j]-lus[ch][i-j+n]-rus[j];
            }
        }
    }
    printf("%lld %lld\n",ans[0],ans[1]);
}
int main(){
    input();
    pro();
}