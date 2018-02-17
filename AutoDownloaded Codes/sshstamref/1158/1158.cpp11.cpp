#include <bits/stdc++.h>
using namespace std;
struct CL{
    int v;
    CL *l, *r;
} tam[5000];
void poop(CL *x){
    x->l->r=x->r;
    x->r->l=x->l;
}
int arr[5000];
int main(){
    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++) tam[i].v=i,tam[i].r=&tam[(i+1)%n],tam[i].l=&tam[(i+n-1)%n];
    CL *p = &tam[n-1];
    for(int i=0;i<n;){
        for(int j=0;j<m;j++){
            p=p->r;
        }
        poop(p);
        arr[i++]=p->v;
    }
    for(int i=0*putchar('<');i<n;i++){
        printf("%d%c ",arr[i]+1,",>"[i==n-1]);
    }
    return 0;
}