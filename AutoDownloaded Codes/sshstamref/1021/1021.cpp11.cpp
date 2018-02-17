#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;
deque<int> dq;
int n, m, x, r;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        dq.push_back(i);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        if (dq.front() == x)
            dq.pop_front();
        else {
            int idx = 0;
            for (auto here : dq) {
                if (here == x)
                    break;
                idx++;
            }
            if ((dq.size() / 2) < idx) {
                while (dq.front() != x) {
                    int y = dq.back();
                    dq.pop_back();
                    dq.push_front(y);
                    r++;
                }
                dq.pop_front();
            }
            else {
                while (dq.front() != x) {
                    int y = dq.front();
                    dq.pop_front();
                    dq.push_back(y);
                    r++;
                }
                dq.pop_front();
            }
        }
    }
    printf("%d\n", r);
    return 0;
}