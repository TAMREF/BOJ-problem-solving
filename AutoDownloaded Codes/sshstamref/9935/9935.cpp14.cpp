#include <bits/stdc++.h>
using namespace std;
vector<pair<char,int> > tam;
char a[1111111], e[40];
int main()
{
    scanf("%s",a);
    scanf("%s",e);
    int len=strlen(a), len2=strlen(e);
    for(int i=0;i<len;i++)
    {
        if(tam.empty()){
            if(a[i]==e[0] && len2==1) continue;
            tam.push_back({a[i],a[i]==e[0]});
        }
        else
        {
            int top=tam.back().second;
            if(a[i]==e[top])
            {
                if(++top==len2) while(--top) tam.pop_back();
                else tam.push_back({a[i],top});
            }
            else tam.push_back({a[i],a[i]==e[0]});
        }
    }
    if(tam.empty()) puts("FRULA");
    else for(pair<char,int> &t : tam) putchar(t.first);
    return 0;
}
