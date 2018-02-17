#include <bits/stdc++.h>
using namespace std;

char L[10], R[20], X[30], T[10];
char P[2005];
int dp[505][2005];
int vis[505];
int m;

struct node{
    string name;
    string val;
    node *l, *r;
    int idx;
    void init(){
        name = "";
        val = "";
        l = nullptr;
        r = nullptr;
    }
} tam[505];

int ncnt;

unordered_map<string,int> Idx;

void makenode(){
    char *p = strchr(R,'+');

    if(!Idx[L]){
        tam[++ncnt].name = L;
        tam[ncnt].idx = Idx[L] = ncnt;
    }
    int now = Idx[L];
    if(!p){
        tam[now].val = R;

        int len = strlen(R);
        tam[now].l = nullptr;
        tam[now].r = nullptr;
    }else{
        assert(*(p-1) == ' ');
        assert(*(p+1) == ' ');
        *(p-1) = 0;

        if( !Idx[R] ){
            tam[++ncnt].name = R;
            tam[ncnt].idx = Idx[R] = ncnt;
        }

        if( !Idx[p+2] ){
            tam[++ncnt].name = p+2;
            tam[ncnt].idx = Idx[p+2] = ncnt;
        }

        tam[now].l = tam + Idx[R];
        tam[now].r = tam + Idx[p+2];
    }
}

void dfs(node *x){

    vis[x->idx] = 1;

    if(x->l){
        if(!vis[x->l->idx]) dfs(x->l);
        if(!vis[x->r->idx]) dfs(x->r);
        for(int i = 0 ; i <= m ; i++){
            dp[x->idx][i] = dp[x->r->idx][ dp[x->l->idx][i] ];
        }
    }
    else{
        int tk = x->idx;
        for(int i = 0, c = (x->val).size() ; i <= m ; i++){
            dp[tk][i] = i;
            for(int j = 0 ; j < c ; j++){
                if(x->val[j] == P[ dp[tk][i] ]){
                    ++dp[tk][i];
                }
            }
        }
    }
}

int main(){
    int t, k;
    //freopen("1.in","rt",stdin);
    //freopen("1.myout","wt",stdout);

    /*
    //Scoring
    freopen("1.myout","rt",stdin);
    FILE *fp = fopen("1.out","rt");
    char S1[100], S2[100];
    int cnt = 0, tot = 0;
    for(;;++tot){
        if(!fgets(S1,10,stdin)) break;
        fgets(S2,10,fp);
        S1[strlen(S1)-1] = 0;
        S2[strlen(S2)-1] = 0;
        if(!strcmp(S1,S2)) ++cnt;
        else printf("WA on TC #%d. Expected :%s, Your ans : %s\n",tot,S2,S1);
    }
    return !printf("%d AC / %d TC\n",cnt,tot);
    */

    for(scanf("%d",&t);t--;){
        for(int i=0;i<505;i++) tam[i].init();

        memset(vis,0,sizeof(vis));
        memset(dp,0,sizeof(dp));

        Idx.clear(); ncnt = 0;
        scanf("%d\n",&k);
        for(int i=0;i<k;i++){
            scanf("%s%*c%*c%*c",L);
            fgets(R,15,stdin);
            R[strlen(R)-1] = 0;
            makenode();
        }
        fgets(T,8,stdin);
        T[strlen(T)-1] = 0;

        fgets(P,2003,stdin);
        m = strlen(P)-1;
        P[m] = 0;
        //printf("P = \"%s\"\n",P);

        dfs( tam + Idx[T] );
        /*
        for(auto i : Idx){
            cout<<"dp[ ("<<i.first<<", "<<i.second<<") ] : ";
            for(int j=0;j<m;j++){
                printf("%d ",dp[i.second][j]);
            }
            puts("");
        }
        */
        puts( dp[ Idx[T] ][0] == m ? "YES" : "NO" );
        //printf("recursion = %d times.\n",reccnt);
    }
}