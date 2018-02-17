#include <bits/stdc++.h>
using namespace std;
struct trie{
    bool isend;
    trie* des[10];
    trie(bool e=true):isend(e){for(int i=0;i<10;i++) des[i]=NULL;}
};
int main(){
    int T;
    for(scanf("%d\n",&T);T--;){
        int N,i=0; scanf("%d\n",&N);
        trie *root = new trie(false);
        char s[20]={};
        for(;i<N;i++){
            fgets(s,15,stdin);
            for(int j=0;j<15;j++) if(s[j]==0x0A) s[j]=0;
            int k=strlen(s), flag=1;
            trie *now=root;
            for(int j=0;j<k;j++){
                trie **ptr = &now->des[s[j]&15];
                if(flag && now->isend) goto FAIL;
                else if(flag && *ptr!=NULL) now=*ptr;
                else{
                    flag=0;
                    if(*ptr==NULL) *ptr=new trie(false);
                    now=*ptr;
                }
            }
            if(flag) goto FAIL;
            now->isend=true;
        }
        puts("YES");
        continue;
        FAIL:
        puts("NO");
        for(int trash;++i<N;) scanf("%d\n",&trash);
    }
}