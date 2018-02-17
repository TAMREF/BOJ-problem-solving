#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
using namespace std;
int N, M;
int grid[100][100];
int vertexN;
int queueY[10002], queueX[10002];
int flag[100][100];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int tmpN, edgeN;
struct Edge
{
    int s, e;
    bool operator < (const Edge &rhs)
    {
        if (s == rhs.s)
            return e < rhs.e;
        return s < rhs.s;
    }
    bool operator == (const Edge &rhs)
    {
        return s == rhs.s && e == rhs.e;
    }
};
Edge tmp[40000], edges[40000];
int edgeIdx[10002];
int dist[10001];
int flag2[10001];
void floodFill(int startY, int startX)
{
    int k;
    int mark = grid[startY][startX];
    int head = -1, tail = 0;
    queueY[0] = startY, queueX[0] = startX;
    vertexN++;
    flag[startY][startX] = vertexN;
    while (head < tail)
    {
        head++;
        int y = queueY[head];
        int x = queueX[head];
        for (k = 0; k < 4; k++)
        {
            int wy = y + dy[k];
            int wx = x + dx[k];
            if (0 <= wy && wy < N && 0 <= wx && wx < M)
            {
                if (grid[wy][wx] == mark && flag[wy][wx] == 0)
                {
                    flag[wy][wx] = vertexN;
                    tail++;
                    queueY[tail] = wy;
                    queueX[tail] = wx;
                }
                else if (flag[wy][wx] && flag[wy][wx] != vertexN)
                {
                    tmp[tmpN].s = vertexN;
                    tmp[tmpN].e = flag[wy][wx];
                    tmpN++;
                    tmp[tmpN].s = flag[wy][wx];
                    tmp[tmpN].e = vertexN;
                    tmpN++;
                }
            }
        }
    }
}
void buildGraph(void)
{
    int i, j;
    floodFill(N / 2, M / 2);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (flag[i][j] == 0)
                floodFill(i, j);
        }
    }
    if (tmpN)
    {
        sort(tmp, tmp + tmpN);
        edgeN = unique(tmp, tmp + tmpN) - tmp;
        for (i = 0; i < edgeN; i++)
        {
            edges[i] = tmp[i];
            edgeIdx[edges[i].s + 1] = i + 1;
        }
        edgeIdx[1] = 0;
        edgeIdx[vertexN + 1] = edgeN;
    }
}
int getRadius(void)
{
    int i, j, radius = vertexN;
    for (i = 1; i <= vertexN; i++)
        flag2[i] = 0;
    for (i = 1; i <= vertexN; i++)
    {
        if (flag2[i] >= radius)
            continue;
        for (j = 1; j <= vertexN; j++)
            dist[j] = -1;
        int head = -1, tail = 0;
        queueX[0] = i;
        dist[i] = 0;
        int max_distance = 0;
        while (head < tail)
        {
            head++;
            int x = queueX[head];
            for (j = edgeIdx[x]; j < edgeIdx[x + 1]; j++)
            {
                int y = edges[j].e;
                if (dist[y] == -1)
                {
                    dist[y] = dist[x] + 1;
                    if (max_distance < dist[y])
                        max_distance = dist[y];
                    if (dist[y] > flag2[y])
                        flag2[y] = dist[y];
                    queueX[++tail] = y;
                }
            }
        }
        if (radius > max_distance)
        {
            radius = max_distance;
        }
    }
    return radius;
}
int main(void)
{
    FILE *fin = stdin;
    fscanf(fin, "%d %d", &N, &M);
    assert(1 <= N && N <= 100);
    assert(1 <= M && M <= 100);
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            fscanf(fin, "%d", &grid[i][j]);
            assert(grid[i][j] == 0 || grid[i][j] == 1);
        }
    }
    fclose(fin);
    buildGraph();
    FILE *fout = stdout;
    int ret = getRadius();
    fprintf(fout, "%d\n", ret);
    fclose(fout);
    return 0;
}
