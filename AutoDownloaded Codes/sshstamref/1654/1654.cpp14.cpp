#include <cstdio>
#include <climits>
int main()
{
    int K, N, a[10000]; scanf("%d %d", &K, &N);
    for (int i = 0; i < K; i++) scanf("%d", &a[i]);
    long long l = 0, r = LLONG_MAX - 1, m, cnt;
    while (l <= r){
        m = (l + r) / 2;
        cnt = 0;
        for (int i = 0; i < K; i++) cnt += a[i] / m;
        if (cnt < N) r = m - 1;
        else l = m + 1;
    }
    printf("%d\n", l - 1);
    return 0;
}