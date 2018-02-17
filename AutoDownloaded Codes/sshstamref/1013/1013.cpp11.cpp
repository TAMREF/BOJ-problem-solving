#include <cstdio>
 
int main()
{
    int t;
    scanf("%d", &t);
 
    while (t--)
    {
        char *p, dat[205] = "";
        scanf(" %s", p = dat);
 
        while (*p)
        {
            if (*p++ == '1')
            {
                int cnt = 0;
                while (*p == '0') ++p, ++cnt;
                if (cnt < 2) goto EXIT;
 
                cnt = 0;
                while (*p == '1' && (p[1] == 0 || p[1] == '1' || p[2] == '1')) ++p, ++cnt;
                if (cnt < 1) goto EXIT;
            }
            else
            {
                if (*p != '1') goto EXIT;
                ++p;
            }
        }
 
        puts("YES");
        continue;
 
    EXIT:
        puts("NO");
    }
 
    return 0;
}
