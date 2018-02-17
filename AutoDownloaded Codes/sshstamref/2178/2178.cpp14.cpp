#include <cstdio>
struct Point {
    int y, x;
};
int main()
{
    int N, M, step, i, j, sz, y, x, head, tail;
    bool map[101][101];
    Point p, queue[10000];
    scanf("%d %d", &N, &M);
    for (i=1;i<=N;i++)
        for (j=1;j<=M;j++){
            scanf("%1d", &map[i][j]);
            map[i][j]=!map[i][j];
        }
    head=tail=0;
    step=map[1][1]=1;
    queue[tail++] = { 1, 1 };
    while (head!=tail){
        sz = tail - head;
        for (i = 0; i < sz; i++) {
            p = queue[head++];
            y = p.y, x = p.x;
            if (y == N && x == M) goto EXIT;
            if (y - 1 > 0 && !map[y - 1][x]) {
                map[y - 1][x] = 1;
                queue[tail++] = { y - 1, x };
            }
            if (y + 1 <= N && !map[y + 1][x]) {
                map[y + 1][x] = 1;
                queue[tail++] = { y + 1, x };
            }
            if (x - 1 > 0 && !map[y][x - 1]) {
                map[y][x - 1] = 1;
                queue[tail++] = { y, x - 1 };
            }
            if (x + 1 <= M && !map[y][x + 1]) {
                map[y][x + 1] = 1;
                queue[tail++] = { y, x + 1 };
            }
        }
        step++; 
    } 
EXIT:
    printf("%d", step);
    return 0;
}