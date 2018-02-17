#include<cstdio>
#include<algorithm>
using namespace std;
int n, dp1[10000], dp2[10000];
int main() {
    scanf("%d", &n);
    for (int i = 1, x; i < n; i++) {
        scanf("%d", &x);
        for (int j = i; j > 1; j--) dp2[j] = min(dp1[j - 1], dp1[i + 1 - j] + x);
        dp2[1] = x;
        copy(dp2, dp2 + 1 + i, dp1);
    }
    printf("%d", dp1[n / 2]);
    return 0;
}