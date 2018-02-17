#include <bits/stdc++.h>
using namespace std;

char A[10005], B[10005];
vector<char> p,q,r;
int main(){
    scanf("%s %s",A,B);
    for(int i=strlen(A);i--;){
        p.push_back(A[i]-'0');
    }
    for(int i=strlen(B);i--;){
        q.push_back(B[i]-'0');
    }
    int l = max(p.size(),q.size());
    p.resize(l); q.resize(l); r.resize(l+1);
    for(int i=0;i<l;i++){
        r[i] += p[i] + q[i];
        if(r[i] > 9) r[i] %= 10, ++r[i+1];
    }
    while(r.back() == 0) r.pop_back();
    for(int i = r.size(); i--; printf("%d",r[i]));
    puts("");
}