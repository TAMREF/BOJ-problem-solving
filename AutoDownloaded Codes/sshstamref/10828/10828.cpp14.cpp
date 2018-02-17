#include <cstdio>
int tam_stack[10003], ed,N,x;
char query[15];
int main()
{
    for(scanf("%d",&N);N--;)
    {
        scanf("%s",query);
        switch(query[0])
        {
        case 'p':
            if(query[1]=='u')
            {
                scanf("%d",&x);
                tam_stack[ed++]=x;
            }
            else printf("%d\n",(ed>0)?(tam_stack[--ed]):(-1));
            break;
        case 'e': printf("%d\n",ed==0); break;
        case 's': printf("%d\n",ed); break;
        case 't': printf("%d\n",(ed)?(tam_stack[ed-1]):(-1));
        }
    }
    return 0;
}
