#include <stdio.h>
#include <climits>
int N, K;
long long max, lan[11111];
int main(){
    scanf("%d %d", &K, &N);
    for (int i = 0; i < K; i++) scanf("%lld", &lan[i]);
    long long left = 0, right=INT_MAX;
    while (left <= right){
        long long mid = (left + right) / 2;
        int result=0;
        for (int i = 0; i < K; i++) result += lan[i] / mid;
        if (result >= N)
        {
            left = mid + 1;
            if (mid > max) max = mid;
        }
        else
            right = mid - 1;
    }
    printf("%lld\n", max); 
    return 0;
}