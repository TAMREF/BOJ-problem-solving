#include <cstdio>
#include <algorithm>
struct point{int x, y;};
bool operator< (point a, point b){if(a.y==b.y) return a.x<b.x; return a.y<b.y;}
int N;
point tam[111111];
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d%d",&tam[i].x,&tam[i].y);
    std::sort(tam,tam+N);
    for(int i=0;i<N;i++) printf("%d %d\n",tam[i].x,tam[i].y);
    return 0;
}
