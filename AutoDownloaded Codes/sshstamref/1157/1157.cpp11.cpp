#include <bits/stdc++.h>
using namespace std;
int s[256], n;
char a[1000005];
int main()
{
    scanf("%s",a); n = strlen(a);
    for(int i=0;i<n;i++) s[islower(a[i])?a[i]:tolower(a[i])]++;
    int x = 0, flag = 1;
    char c;
    for(char i='a';i<='z';i++){
        if(s[i]>x){
            x = s[i];
            flag = 1;
            c = i;
        }else if(s[i] == x){
            flag = 0;
        }
    }
    putchar(flag?toupper(c):'?');
    return 0;
}