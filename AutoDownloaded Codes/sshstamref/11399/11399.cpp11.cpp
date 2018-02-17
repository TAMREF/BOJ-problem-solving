#include <cstdio>
#include <algorithm>
struct p{
    int ind, time;
} tam[1000];
bool cmp(p a, p b)
{
    return a.time<b.time;
}
int main(){
    int N; long long T=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++) {scanf("%d",&tam[i].time); tam[i].ind=i+1;}
    std::sort(tam,tam+N,cmp);
    for(int i=0;i<N;i++) T+=(N-i)*tam[i].time;
    printf("%lld\n",T);
}