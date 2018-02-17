#include <bits/stdc++.h>
using namespace std;
const double r = 0.999;
const double Tc = 3.;
const double boltz = 0.7;
const int step = 10000;

typedef unsigned int ui;

random_device rd;
mt19937_64 gen(rd()+(unsigned int)time(0));
uniform_real_distribution<> pr(0.,1.);
uniform_int_distribution<long long> dist(0,1LL<<32);

double T = 1000.;


ui n, mask;
int ans;

struct board{
    ui row[32];
    void fliprow(ui x){
        for(int i=0;i<n;i++)
            if(x>>i&1) row[i] = ~row[i];
    }
    void flipcol(ui x){
        for(int i=0;i<n;i++)
            row[i] ^= x;
    }
    void rndflip(){
        fliprow(dist(gen));
        flipcol(dist(gen));
    }
    void select_1_rc(){
        fliprow(1u<<(dist(gen)&31));
        flipcol(1u<<(dist(gen)&31));
    }
    int E(){
        int S = 0;
        for(int i=0;i<n;i++)
            S += __builtin_popcount(row[i] & mask);
        return S;
    }
    void printboard(){
        printf("E = %d\n",E());
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%d",row[i]>>j&1);
            }
            puts("");
        }
        puts("");
    }
} B, C;

char buf[40];
void input(){
    scanf("%d",&n);
    mask = (1u<<n)-1;
    for(int i=0;i<n;i++){
        scanf("%*c%s",buf);
        for(int j=0;j<n;j++){
            B.row[i] |= (buf[j]=='T'?1<<j:0);
        }
    }
    ans = B.E();
    for(int i=0;i<n;i++){
        C.row[i] = B.row[i];
    }
}

int SA(){
    double myP;
    int e0;
    while(T > Tc){
        (dist(gen)%3?C.select_1_rc():C.rndflip());
        e0 = C.E();
        ans = min(ans,e0);
        myP = exp((B.E()-e0)/(boltz * T));
        if(myP > pr(gen)){
            //C.printboard();
            for(int i=0;i<n;i++)
                B.row[i] = C.row[i];
        }
        for(int i=0;i<n;i++){
            C.row[i] = B.row[i];
        }
        T *= r;
    }
    return ans;
}
void random_board(){
    int bn = 15;
    freopen("sample.txt","wt",stdout);
    printf("%d\n",bn);
    for(int i=0;i<bn;i++){
        for(int j=0;j<bn;j++){
            printf("%c",dist(gen)&1?'H':'T');
        }
        puts("");
    }
    exit(0);
}
int brute_force(){
    int ans = 1024;
    for(int b = 0;b<mask;b++){
        C.flipcol(b);
        int fm = 0;
        for(int i=0;i<n;i++){
            if(__builtin_popcount(C.row[i])>n/2) fm|=(1<<i);
        }
        C.fliprow(fm);
        ans = min(ans,C.E());
        C.fliprow(fm);
        C.flipcol(b);
    }
    for(int i=0;i<n;i++) C.row[i] = B.row[i];
    return ans;
}
int main(){
    //random_board();
    //freopen("sample.txt","rt",stdin);
    input();
    printf("%d\n",brute_force());
    //printf("%d\n",SA());
}
