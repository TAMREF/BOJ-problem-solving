#include <bits/stdc++.h>
using namespace std;

int n, a[100005];

int main() {
    scanf("%d", &n);

    int before = -1;
    int pos = 1;

    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);

        if (before == t) pos++;

        a[pos]++;
        before = t;
    }

    int ret = 0;
    for (int i = 1; i <= pos; i++) {
        ret = max(ret, a[i - 1] + a[i] + a[i + 1]);
    }

    printf("%d", ret);

    return 0;
}
