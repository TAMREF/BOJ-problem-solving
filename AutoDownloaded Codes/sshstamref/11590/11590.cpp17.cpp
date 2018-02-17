#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef pair<ll,ll> pll;

const int mx = 2e6 + 5;
const ll mod[2] = {1000000007LL,1610612741LL};

map<ll,int> M;

char S[mx];
unsigned int pfx[2][mx], sfx[2][mx];
unsigned int pow_27[2][mx] = {{1u},{1u}};
int n;

void init(){
    scanf("%d",&n);
    for(int b=0;b<2;b++)
        for(int i=1;i<mx;i++)
            pow_27[b][i] = 27LL * pow_27[b][i-1] % mod[b];
}

void update(){
    scanf("%*c%s",S+1);
    int l = strlen(S+1);

    for(int b = 0; b < 2 ; b++)
    for(int i = 1; i <= l; i++){
        pfx[b][i] = (27LL * pfx[b][i-1] + (S[i] - 'A' + 1)) % mod[b];
    }

    sfx[0][l+1] = sfx[1][l+1] = 0;

    for(int b = 0; b <  2; b++)
    for(int i = l; i >= 1; i--){
        sfx[b][i] = ((ll)pow_27[b][l-i] * (S[i] - 'A' + 1) + sfx[b][i+1]) % mod[b];
    }

    int dlen = 1;
    for(int i = 1; i <= l; i++){
        if(pfx[0][i] == sfx[0][l+1-i] && pfx[1][i] == sfx[1][l+1-i]){
            dlen = max(dlen, M[(ll)pfx[0][i] << 32 | pfx[1][i]] + 1);
        }
    }
    M[(ll)pfx[0][l] << 32 | pfx[1][l]] = dlen;
}

void output(){
    int ans = 1;
    for(auto p : M){
        ans = max(ans, p.second);
    }
    printf("%d\n",ans);
}

int main(){
    init();
    for(int i=1;i<=n;i++){
        update();
    }
    output();
}
