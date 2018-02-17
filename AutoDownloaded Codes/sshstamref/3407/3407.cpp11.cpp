#include <bits/stdc++.h>
using namespace std;
char* Elem[114] = {
"ac", "ag", "al", "am", "ar", "as", "at", "au", "b", "ba", "be", "bh", "bi", "bk", "br", "c", "ca", "cd", "ce", "cf", "cl", "cm", "cn", "co", "cr", "cs", "cu", "db", "ds", "dy", "er", "es", "eu", "f", "fe", "fl", "fm", "fr", "ga", "gd", "ge", "h", "he", "hf", "hg", "ho", "hs", "i", "in", "ir", "k", "kr", "la", "li", "lr", "lu", "lv", "md", "mg", "mn", "mo", "mt", "n", "na", "nb", "nd", "ne", "ni", "no", "np", "o", "os", "p", "pa", "pb", "pd", "pm", "po", "pr", "pt", "pu", "ra", "rb", "re", "rf", "rg", "rh", "rn", "ru", "s", "sb", "sc", "se", "sg", "si", "sm", "sn", "sr", "ta", "tb", "tc", "te", "th", "ti", "tl", "tm", "u", "v", "w", "xe", "y", "yb", "zn", "zr"
};

char* S;

const int numSing = 14, numElem = 114;

bool dp[2][50002];



void init(){
    sort(Elem, Elem + numElem,[](char* u, char* v){
            int len1 = strlen(u), len2 = strlen(v);
            return len1==len2?lexicographical_compare(u,u+len1,v,v+len2):len1<len2;
        });
}

inline bool cmp1(char* u, char* v){
    return *u<*v;
}

inline bool cmp2(char* u, char* v){
    return *u==*v?*(u+1)<*(v+1):*u<*v;
}

void dynamic(){
    int n = strlen(S);

    int ic = lower_bound(Elem, Elem + numSing, S, cmp1) - Elem;
    if(ic != numSing){
        dp[0][0] = !strncmp(Elem[ic], S, 1);
    }

    ic = lower_bound(Elem, Elem + numSing, S+1, cmp1) - Elem;
    if(ic != numSing){
        dp[0][1] = dp[0][0] && !strncmp(Elem[ic], S+1, 1);
    }

    ic = lower_bound(Elem + numSing, Elem + numElem, S, cmp2) - Elem;
    if(ic != numElem){
        dp[1][1] = !strncmp(Elem[ic], S, 2);
    }

    if(!dp[0][0] && !dp[0][1] && !dp[1][1]){
        puts("NO");
        return;
    }

    for(int i=2;i<n;i++){

        ic = lower_bound(Elem, Elem + numSing, S+i, cmp1) - Elem;
        if(ic != numSing){
           //printf("i = %d, Elem[%d] = %s\n",i,ic,Elem[ic]);
            dp[0][i] = (dp[0][i-1] || dp[1][i-1]) && !strncmp(Elem[ic], S+i, 1);
        }

        ic = lower_bound(Elem + numSing, Elem + numElem, S+i-1, cmp2) - Elem;
        if(ic != numElem){
            //printf("i = %d, Elem[%d] = %s\n",i,ic,Elem[ic]);
            //puts(Elem[ic]);
            dp[1][i] = (dp[0][i-2] || dp[1][i-2]) && !strncmp(Elem[ic], S+i-1, 2);
        }

        if(!dp[0][i-1] && !dp[1][i-1] && !dp[0][i] && !dp[1][i]){
            //printf("Failed in %d\n",i);
            puts("NO");
            return;
        }
    }
    puts( !dp[0][n-1] && !dp[1][n-1] ? "NO" : "YES");
}

int main(){
    init();
    int t;
    S = (char*)malloc(50002);
    for(scanf("%d",&t);t--;){
        scanf("%*c%s",S);
        memset(dp,0,sizeof(dp));
        dynamic();
    }
}