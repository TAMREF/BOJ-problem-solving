#include <bits/stdc++.h>
using namespace std;
const int o = 131072;
struct Idxtree{
   int O[o+o];
   void init(){
       for(int x = o ; x > 1; x >>= 1){
           for(int y = x; y < x+x ; y += 2){
                O[ y >> 1 ] = min(O[y], O[ y^1 ]);
           }
       }
   }
   void update(int i, int v){
       i += o;
       O[i] = v;
       while(i>1){
           O[i >> 1] = min(O[i], O[i^1]);
           i >>= 1;
       }
   }
   int gmin(int s, int e){
       s += o; e += o;
       int m = min(O[s],O[e]);
       while( s <= e){
            m = min({m, O[s], O[e]});
            ++s >>= 1;
            --e >>= 1;
       }
       return m;
   }
} I;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n;
    for(int i=0;i<n;i++) cin>>I.O[o+i];
    I.init();
    cin>>q;
    for(int ty,a,b;q--;){
        cin>>ty;
        if(ty==1){
            cin>>a>>b;
            I.update(a-1,b);
        }else{
            cin>>a>>b;
            cout<<I.gmin(a-1,b-1)<<'\n';
        }
    }
    return 0;
}