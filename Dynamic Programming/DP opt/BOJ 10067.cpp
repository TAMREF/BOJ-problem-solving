#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,int> pli;

const int mx = 100005;
const ll inf = 2e18;

long double get_cross(ll a1, ll b1, ll a2, ll b2){
    return (long double)(b2-b1)/(a1-a2);
}
struct CHT{
    ll A[mx], B[mx];
    int I[mx];
    int p, sz;
    pli query(ll x){
        //printf("*got a query. x = %lld, p = %d, sz = %d\n",x,p,sz);
        while(p + 1 < sz && (A[p+1] - A[p]) * x <= B[p] - B[p+1]) ++p;
        return {A[p] * x + B[p], I[p]};
    }
    void insert(ll a, ll b, int i){
        //printf("\n----inserting y = %lld x + %lld, idx = %d----\n",a,b,i);
        A[sz] = a;
        B[sz] = b;
        I[sz] = i;
        //while(p + 1 < sz && get_cross(A[sz-2],B[sz-2],A[sz],B[sz]) > get_cross(A[sz-1],B[sz-1],A[sz],B[sz])){
        while(p+1<sz && (B[sz] - B[sz-2]) * (A[sz-1] - A[sz]) >= (A[sz-2] - A[sz])* (B[sz] - B[sz-1])){
            //printf("val1 : %lld, val2 : %lld\n",(B[sz] - B[sz-2]) * (A[sz-1] - A[sz]),(A[sz-2] - A[sz])* (B[sz] - B[sz-1]));
            //printf("removing y = %lld x + %lld\n",A[sz-1],B[sz-1]);
            A[sz-1] = A[sz];
            B[sz-1] = B[sz];
            I[sz-1] = I[sz];
            --sz;
        }
        ++sz;
    }
    void clear(){
        sz = p = 0;
    }
} C;

int a[mx], S[mx];
int n, k;
ll D[mx][2];
int bck[mx][205];

void input(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> S[i];
        S[i] += S[i-1];
    }
}

void fucking_cht(){
    for(int i = 1; i <= n; i++) D[i][0] = inf;
    for(int l = 1, w = 1; l <= k + 1; l++, w ^= 1){
        //printf("\n#####lev = %d#####\n",l);
        C.clear();
        C.insert(0,0,0);
        for(int i = l-1; i <= n; i++){
            if(i >= l){
                pli p = C.query(S[i]);
                D[i][w] = p.first + (ll)S[i] * S[i];
                bck[i][l] = p.second;
                //printf("S[%d] = %d, D[%d][%d] = %lld, bck[%d][%d] = %d\n",i,S[i],i,l,D[i][w],i,l,bck[i][l]);
            }
            if(D[i][!w] != inf) C.insert(-2LL * S[i], D[i][!w] + (ll)S[i] * S[i], i);
        }
    }

    cout << ((ll)S[n] * S[n] - D[n][(k+1)&1])/2 << '\n';

    stack<int> trace;
    for(int i = k+1, now = n; i >= 1; i--){
        trace.push(bck[now][i]);
        now = bck[now][i];
    }
    trace.pop();
    for(int i=0;i<k;i++){
        cout << trace.top() << ' ';
        trace.pop();
    }
}

void expected_answer(){
    FILE *fp = fopen("sequence/02.a","rt");
    ll ans;
    fscanf(fp,"%lld",&ans);
    //printf("ans = %lld\nseq = ",ans);
    for(int i = 0; i < k; i++){
        fscanf(fp,"%d",&ans);
        //printf("%d ",ans);
    }
    puts("");
}

int main(){
    freopen("sequence/02","rt",stdin);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    fucking_cht();
}
