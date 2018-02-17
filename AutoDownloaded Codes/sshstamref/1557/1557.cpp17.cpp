#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 2e9, sqinf = (int)sqrt(inf) + 5;

long long p[4700] = {2};
int eop = 1;
bool chk[sqinf];

void buildprime(){
    for(int i = 3; i * i <= inf; i+=2){
        if(chk[i]) continue;
        p[eop++] = i;
        for(long long j = i*i; j * j <= inf; j += (i+i)){
            chk[j] = true;
        }
    }
    //printf("%d\n",eop);
}

ll gazua(unsigned int k){
    int b, c, d, e, f, g, h;
    int kb, kc, kd, ke, kf, kg, kh;

    ll cnt = 0;

    for(b = 0; p[b] * p[b] <= k ; b++){
        kb = k / p[b] / p[b];
        cnt += kb;
    }

    for(b = 0; p[b] * p[b] <= k ; b++){
        kb = k / p[b] / p[b];
        for(c = b + 1; p[c] * p[c] <= kb; c++){
            kc = kb / p[c] / p[c];
            cnt -= kc;
        }
    }

    for(b = 0; p[b] * p[b] <= k ; b++){
        kb = k / p[b] / p[b];
        for(c = b + 1; p[c] * p[c] <= kb; c++){
            kc = kb / p[c] / p[c];
            for(d = c + 1; p[d] * p[d] <= kc ; d++){
                kd = kc / p[d] / p[d];
                cnt += kd;
            }
        }
    }

    for(b = 0; p[b] * p[b] <= k ; b++){
        kb = k / p[b] / p[b];
        for(c = b + 1; p[c] * p[c] <= kb; c++){
            kc = kb / p[c] / p[c];
            for(d = c + 1; p[d] * p[d] <= kc ; d++){
                kd = kc / p[d] / p[d];
                for(e = d + 1; p[e] * p[e] <= kd; e++){
                    ke = kd / p[e] / p[e];
                    cnt -= ke;
                }
            }
        }
    }

    for(b = 0; p[b] * p[b] <= k ; b++){
        kb = k / p[b] / p[b];
        for(c = b + 1; p[c] * p[c] <= kb; c++){
            kc = kb / p[c] / p[c];
            for(d = c + 1; p[d] * p[d] <= kc ; d++){
                kd = kc / p[d] / p[d];
                for(e = d + 1; p[e] * p[e] <= kd; e++){
                    ke = kd / p[e] / p[e];
                    for(f = e + 1; p[f] * p[f] <= ke; f++){
                        kf = ke / p[f] / p[f];
                        cnt += kf;
                    }
                }
            }
        }
    }

    for(b = 0; p[b] * p[b] <= k ; b++){
        kb = k / p[b] / p[b];
        for(c = b + 1; p[c] * p[c] <= kb; c++){
            kc = kb / p[c] / p[c];
            for(d = c + 1; p[d] * p[d] <= kc ; d++){
                kd = kc / p[d] / p[d];
                for(e = d + 1; p[e] * p[e] <= kd; e++){
                    ke = kd / p[e] / p[e];
                    for(f = e + 1; p[f] * p[f] <= ke; f++){
                        kf = ke / p[f] / p[f];
                        for(g = f + 1; p[g] * p[g] <= kf; g++){
                            kg = kf / p[g] / p[g];
                            cnt -= kg;
                        }
                    }
                }
            }
        }
    }

    for(b = 0; p[b] * p[b] <= k ; b++){
        kb = k / p[b] / p[b];
        for(c = b + 1; p[c] * p[c] <= kb; c++){
            kc = kb / p[c] / p[c];
            for(d = c + 1; p[d] * p[d] <= kc ; d++){
                kd = kc / p[d] / p[d];
                for(e = d + 1; p[e] * p[e] <= kd; e++){
                    ke = kd / p[e] / p[e];
                    for(f = e + 1; p[f] * p[f] <= ke; f++){
                        kf = ke / p[f] / p[f];
                        for(g = f + 1; p[g] * p[g] <= kf; g++){
                            kg = kf / p[g] / p[g];
                            for(h = g + 1; p[h] * p[h] <= kg; h++){
                                kh = kg / p[h] / p[h];
                                cnt += kh;
                            }
                        }
                    }
                }
            }
        }
    }

    return cnt;
}

bool isSquareFree(unsigned int x){
    for(int b = 0; p[b] * p[b] <= x; b++){
        if(x % (p[b] * p[b]) == 0) return false;
    }
    return true;
}

int main(){
    buildprime();
    int k;
    ll t;
    scanf("%d",&k);
    unsigned int lo = 1, hi = INT_MAX, mi;

    while(lo <= hi){
        mi = (lo + hi) / 2;
        t = (ll)mi - gazua(mi);

        //printf("mi = %u, t = %lld\n",mi,t);
        if(t >= k){
            if(t == k){
                if(isSquareFree(mi)){
                    printf("%u\n",mi);
                    return 0;
                }else{
                    hi = mi - 1;
                }
            }else{
                hi = mi - 1;
            }
        }else{
            lo = mi + 1;
        }
    }
}
