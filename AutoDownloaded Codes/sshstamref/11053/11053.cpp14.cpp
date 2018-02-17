#include <iostream>
using namespace std;
int dp[1010], tmp, rear, N;
int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>tmp;
        if(tmp>dp[rear]) dp[++rear]=tmp;
        else
        {
        for(int j=1;j<=rear;j++)
            {
            if(dp[j]>=tmp)
                {
                dp[j]=tmp;
                    break;
            }
        }
    }
}
    cout<<rear<<endl;
    return 0;
}
