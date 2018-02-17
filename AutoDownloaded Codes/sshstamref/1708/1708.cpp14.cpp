#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

vector<pii> convex;
vector<pii> tam;
int N, x, y;

ll operator^ (pii x, pii y)
{
    return (ll)x.first*y.second - (ll)y.first*x.second;
}

pii operator- (pii x, pii y)
{
    return {x.first-y.first,x.second-y.second};
}
inline ll sq(int t) {return (ll)t*t;}
inline ll sz(pii x)
{
    return sq(x.first)+sq(x.second);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>x>>y;
        tam.push_back({x,y});
        if(tam[0]>tam[i]) swap(tam[0],tam[i]);
    }

    for(int i=1;i<N;i++) tam[i]=tam[i]-tam[0];
    tam[0]={0,0};
    sort(tam.begin()+1,tam.end(),[](pii x, pii y)
         {
             if(x^y) return (x^y)<0;
             return sz(x)<sz(y);
         });
    //tam.push_back({0,0});
    //puts(""); for(pii &u : tam) printf("%d %d\n",u.first,u.second); puts("");
    for(pii &p : tam)
    {
        while(convex.size()>=2 && ((convex.back()-convex[convex.size()-2])^(p-convex.back()))>=0) convex.pop_back();
        convex.push_back(p);
    }
    //for(pii &t : convex) printf("%d %d\n",t.first,t.second);
    printf("%d\n",convex.size());
}
