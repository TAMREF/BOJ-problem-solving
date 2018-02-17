#include <bits/stdc++.h>
using namespace std;
unordered_set<string> U;
int main(){
    cin.sync_with_stdio(false);
    int N,M,cnt=0;
    cin>>N;
    for(string x;N--;){
        cin>>x;
        U.insert(x);
    }
    cin>>M;
    for(string x;M--;){
        cin>>x;
        cnt+=(U.find(x)!=U.end()?1:0);
    }
    cout<<cnt<<endl;
}