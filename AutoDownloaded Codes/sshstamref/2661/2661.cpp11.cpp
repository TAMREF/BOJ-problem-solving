#include <bits/stdc++.h>
using namespace std;
priority_queue<string,vector<string>,greater<string>> horrible;
bool isgood(string z){
    int S=z.size();
    for(int i=1;i*2<=S;i++) if(z.substr(S-i,i)==z.substr(S-2*i,i)) return false;
    return true;
}
int main(){
    int N;
    cin>>N;
    horrible.push(string(""));
    string T;
    for(;;){
        T=horrible.top(); horrible.pop();
        for(char x : {'1','2','3'}){
            if(isgood(T+x)){
                if(T.size()==N-1){
                    cout<<T+x<<endl;
                    return 0;
                }
                horrible.push(T+x);
            }
        }
    }
}