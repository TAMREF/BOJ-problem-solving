#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int l[676][676];
int n;
inline ii code(string& z){
    return ii((z[0]-'A')*26+(z[1]-'A'),(z[z.size()-2]-'A')*26+(z.back()-'A'));
}
string buf;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    long long sp=0;
    ii p;
    getline(cin,buf);
    for(int i=0;i<n;i++){
        getline(cin,buf);
        p=code(buf);
        if(p.first!=p.second) sp+=l[p.second][p.first];
        ++l[p.first][p.second];
    }
    cout<<sp<<endl;
    return 0;
}