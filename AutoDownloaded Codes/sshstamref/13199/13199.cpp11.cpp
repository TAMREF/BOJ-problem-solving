#include<cstdio>
int t, p, m, f, c, x, y;
int main() {
    for (scanf("%d", &t); t--;) {
        scanf("%d %d %d %d", &p, &m, &f, &c);
        x = m / p;
        for (int y = x*c; y / f; y = y / f*c + y%f) x += y / f;
        printf("%d\n", x - m / p - m / p*c / f);
    }
    return 0;
}