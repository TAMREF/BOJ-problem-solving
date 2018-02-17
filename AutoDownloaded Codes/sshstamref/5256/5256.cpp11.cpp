#include <bits/stdc++.h>
using namespace std;
const int mx=100005;
int B[mx], A[mx<<1];
int N;
set<int> L;
void input(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&B[i]);
    }
    for(int i=0;i<2*N-1;i++) L.insert(i+1);
}
void solve(){
    L.erase(B[0]);
    A[0]=B[0];
    for(int i=1;i<N;i++){
        if(B[i]==B[i-1]){
            A[2*i-1]=*L.begin(); L.erase(*L.begin());
            A[2*i  ]=*L.rbegin(); L.erase(*L.rbegin());
        }
        else if(B[i]<B[i-1]){
            if(L.find(B[i])==L.end()){
                A[2*i-1]=*L.begin(); L.erase(*L.begin());
                A[2*i  ]=*L.begin(); L.erase(*L.begin());
            }else{
                A[2*i-1]=B[i]; L.erase(B[i]);
                A[2*i  ]=*L.begin(); L.erase(*L.begin());
            }
        }
        else{
            if(L.find(B[i])==L.end()){
                A[2*i-1]=*L.rbegin(); L.erase(*L.rbegin());
                A[2*i  ]=*L.rbegin(); L.erase(*L.rbegin());
            }else{
                A[2*i-1]=B[i]; L.erase(B[i]);
                A[2*i  ]=*L.rbegin(); L.erase(*L.rbegin());
            }
        }
    }
}
int main(){
    input();
    solve();
    for(int i=0;i<2*N-1;i++) printf("%d ",A[i]);
    return 0&puts("");
}