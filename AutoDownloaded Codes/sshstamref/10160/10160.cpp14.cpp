#include <cstdio>
#define R 1000003
#define c 1000000009
long long E[R], A[R], AB[R], ABA[R], ABC[R], ABAB[R], ABCB[R];
int main()
{
    int N, K;
    scanf("%d %d",&N,&K);
    ABCB[4]=ABAB[4]=ABA[3]=ABC[3]=AB[2]=A[1]=E[0]=1;
    for(int i=1;i<=N;i++)
    {
        if(i>4)
        {
            ABCB[i]=(A[i-4]+(K-2)*E[i-5])%c;
            ABAB[i]=(ABA[i-2]+(K-2)*E[i-5])%c;
        }
        if(i>3)
        {
            ABC[i]=(ABCB[i]+A[i-3]+(K-2)*E[i-4])%c;
            ABA[i]=(ABAB[i]+A[i-3]+(K-2)*E[i-4])%c;
        }
        if(i>2)
        {
            AB[i]=(ABC[i]+ABA[i]+(K-2)*E[i-3])%c;
        }
        if(i>1)
        {
            A[i]=(A[i-1]+AB[i]+(K-2)*E[i-2])%c;
        }
        E[i]=(A[i]+(K-1)*E[i-1])%c;
    }
    printf("%lld\n",E[N]);
}
