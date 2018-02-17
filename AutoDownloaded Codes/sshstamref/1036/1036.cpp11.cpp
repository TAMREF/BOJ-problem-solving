#include <cstdio>
#include <cstring>

inline int chrToint(char c) { return c <= '9' ? c-48 : c-55; }
inline char intTochr(int n) { return n <= 9 ? n+48 : n+55; }
inline double myPow(int n, int r)
{
    double res = 1;
    
    while (r--) res *= n;
    return res;
}
int main()
{
    int n, k;
    int cnt[55][36]{};
    scanf("%d", &n);
    
    char str[51];
    while (n--)
    {
        scanf(" %s", str);
        
        int p = 0;
        for (int i = strlen(str)-1; i >= 0; --i)
            cnt[p++][chrToint(str[i])]++;
    }
    
    scanf("%d", &k);
    
    int alp[36]{};
    while (k--)
    {
        int idx = -1;
        double val, max = 0;
        
        for (int i = 0; i < 35; ++i)
        {
            if (alp[i]) continue;
            
            val = 0;
            for (int j = 0; j < 54; ++j)
                if (cnt[j][i])
                    val += cnt[j][i] * (35-i) * myPow(36, j);
            
            if (max < val)
            {
                idx = i;
                max = val;
            }
        }
        
        if (idx >= 0)
        {
            alp[idx] = 1;
            
            for (int i = 0; i < 55; ++i)
            {
                cnt[i][35] += cnt[i][idx];
                cnt[i][idx] = 0;
            }
        }
        else break;
    }
    
    int sum;
    char ans[55]{};
    for (int i = 0; i < 55; ++i)
    {
        sum = 0;
        for (int j = 0; j < 36; ++j) sum += j*cnt[i][j];
        
        ans[i+1] = (ans[i]+sum) / 36;
        ans[i] = intTochr((ans[i]+sum) % 36);
    }
    
    int flg = 0;
    for (int i = 54; i >= 0; --i)
    {
        if (ans[i] > '0' || i == 0) flg++;
        if (flg) putchar(ans[i]);
    }
    
    return 0;
}