#include<cstdio>
#include<queue>
using namespace std;
typedef long long ll;

const int mx = 100005;

struct info {
    int b, e, c;
} temp;

int N, K, dist[mx], lst[mx], nxt[mx];
bool used[mx];
priority_queue<info> Q;

bool operator < (info A, info B) {
    return A.c > B.c;
}

int main() {
    //freopen("backup/10.in","rt",stdin);

    int i, j, m, l, r, last, pos, b, e, c, taken, B, E, cost;

    scanf("%d %d", &N, &K);

    last = 0;
    while(!Q.empty()) {
        Q.pop();
    }

    for(i = 1; i <= N; i ++) {
        scanf("%d", &pos);
        dist[i] = pos - last;
        last = pos;
        nxt[i] = i+1;
        lst[i] = i-1;
        if(i == 1) {
            continue;
        }
        Q.push({i - 1, i, dist[i]});
    }

    taken = 0, cost = 0;
    while(taken < K) {
        temp = Q.top();
        Q.pop();
        b = temp.b, e = temp.e, c = temp.c;
        if(used[b] || used[e]) {
            continue;
        }

        taken ++;
        cost += c;

        used[b] = true, used[e] = true;
        B = lst[b], E = nxt[e];
        nxt[B] = E, lst[E] = B;

        dist[E] = dist[E] + dist[b] - dist[e];
        if(B >= 1 && E <= N && (!used[B] && !used[E])) {
            Q.push( {B, E, dist[E]});
        }

    }
    printf("%d\n", cost);
    return 0;
}
