#include <bits/stdc++.h>
using namespace std;
int add[3], N;
int tam[2222][2222];
void cut(int sx, int ex, int sy, int ey){
    if(sx==ex) return;
    int rep = tam[sx][sy];
    for(int i=sx;i<ex;i++){
        for(int j=sy;j<ey;j++) if(rep!=tam[i][j]) goto REC;
    }
    ++add[rep+1];
    return;
    REC:
    int ding[4] = {sx,(2*sx+ex)/3,(sx+2*ex)/3,ex}, alpah[4] = {sy,(2*sy+ey)/3,(sy+2*ey)/3,ey};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cut(ding[i],ding[i+1],alpah[j],alpah[j+1]);
        }
    }
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d",&tam[i][j]);
    cut(0,N,0,N);
    for(int p=0;p<3;p++) printf("%d\n",add[p]);
}
