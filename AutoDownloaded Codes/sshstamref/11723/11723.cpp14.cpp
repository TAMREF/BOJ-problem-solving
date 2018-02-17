#include <cstdio>
#include <cstring>
bool a[20];
int main()
{
    int M, tmp; scanf("%d",&M);
    char order[6];
    for(int i=0;i<M;i++)
    {
        scanf("%s %d",order,&tmp);
        if(!strcmp(order,"check")) printf("%d\n",a[tmp-1]);
        else if(!strcmp(order,"remove")) a[tmp-1]=false;
        else if(!strcmp(order,"add")) a[tmp-1]=true;
        else if(!strcmp(order,"toggle")) a[tmp-1]=!a[tmp-1];
        else if(!strcmp(order,"all")) for(int i=0;i<20;i++) a[i]=true;
        else for(int i=0;i<20;i++) a[i]=false;
    }
}
