#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000006;
typedef long long lld;
int N, A, B, C;
int V[MAXN], S[MAXN];
int stk[MAXN], scnt; double xpos[MAXN];
lld D[MAXN];
double get_cross(int p, int q){
    lld a1 = -2LL*A*S[p], b1 = (lld)A*S[p]*S[p] - (lld)B*S[p] + D[p];
    lld a2 = -2LL*A*S[q], b2 = (lld)A*S[q]*S[q] - (lld)B*S[q] + D[q];
    return (double)(b1 - b2) / (a2 - a1);
}
int main(){
    scanf("%d%d%d%d", &N, &A, &B, &C);
    for (int i=1;i<=N;i++) scanf("%d", V+i), S[i] = S[i-1] + V[i];
    int pt = 1;
    for (int i=1;i<=N;i++){
        // j = 0일 때 계산
        D[i] = (lld)A*S[i]*S[i] + (lld)B*S[i] + C;
        if (scnt){
            while (pt < scnt && xpos[pt+1] < S[i]) pt++;
            // j > 0인 j에 대해 점화식 우항이 최대인 j를 구힘
            int j = stk[pt];
            D[i] = max(D[i], D[j] + (lld)A*(S[i]-S[j])*(S[i]-S[j]) + (lld)B*(S[i]-S[j]) + C);
            // 그래프에 일차함수 하나 추가
            while (scnt > 1 && xpos[scnt] > get_cross(stk[scnt], i)) scnt--;
            stk[++scnt] = i;
            xpos[scnt] = get_cross(stk[scnt-1], i);
            if (pt > scnt) pt = scnt;
        }else{
            stk[++scnt] = i;
            xpos[scnt] = -1e18;
        }
    }
    printf("%lld\n", D[N]);
}
