#include <bits/stdc++.h>
using namespace std;
int N;
unordered_map<int,double> h;
unordered_map<int,int> cmap;
void calc(){
    int a[10];
    for(int i=0;i<N;i++) a[i]=i+1;
    do{
        int H=0;
        for(int i=0;i<N;i++) H=9*H+a[i];
        for(int i=0;i<N;i++) for(int j=i+1;j<N;j++) if(a[i]>a[j]) ++cmap[H];
    }while(next_permutation(a,a+N));
}
double E(int* x){
    int C, H=0;
    for(int i=0;i<N;i++) H=9*H+x[i];
    C=cmap[H];
    if(C<2) return (double)C;
    double F=0.0;
    if(h[H]>0.5) return h[H];
    int tmp[10];
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(x[i]>x[j]){
                copy(x,x+N,tmp);
                swap(tmp[i],tmp[j]);
                F+=E(tmp);
            }
        }
    }
    h[H]=F/C+1;
    return h[H];
}
int main(){
    int a[10]={};
    scanf("%d",&N);
    calc();
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    printf("%.10f\n",E(a));
}
