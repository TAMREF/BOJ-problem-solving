#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int mx = 1005;

namespace geo
{
struct pt
{
    ll x, y;
    int i, c;
    pt() {}
    pt(ll x, ll y):x(x),y(y) {}
    pt(ll x, ll y, int i, int c):x(x),y(y),i(i),c(c) {}
    bool operator< (pt z)
    {
        return x==z.x?y<z.y:x<z.x;
    }
    bool operator== (pt z)
    {
        return x==z.x && y==z.y;
    }
    ll operator* (pt z)
    {
        return x * z.y - y * z.x;
    }
    pt operator- (pt z)
    {
        return pt(x - z.x, y - z.y);
    }
    void show()
    {
        //printf("%lld %lld\n",x,y);
    }
};
int ccw(pt u, pt v, pt w)
{
    ll T = (v-u)*(w-u);
    return T?T>0?1:-1:0;
}

ll d(pt u, pt v)
{
    return (u.x-v.x)*(u.x-v.x) + (u.y-v.y)*(u.y-v.y);
}

void andrew(vector<pt>& ch, pt* s, pt* e)
{
    if(s==e)
    {
        ch.resize(1);
        ch.push_back(*s);
        return;
    }
    sort(s,e+1);
    vector<pt> uh, dh;
    for(pt *t = s; t != (e+1); t++)
    {
        for(int c; ( c=uh.size() ) > 1 && ccw(uh[c-2],uh[c-1],*t) <= 0; uh.pop_back());
        uh.push_back(*t);
    }
    for(pt *t = e; t != (s-1); t--)
    {
        for(int c; ( c=dh.size() ) > 1 && ccw(dh[c-2],dh[c-1],*t) <= 0; dh.pop_back());
        dh.push_back(*t);
    }
    ch.resize(uh.size()+dh.size()-2);
    copy( uh.begin(), uh.end(), ch.begin() );
    copy( dh.begin()+1, dh.end()-1, ch.begin() + uh.size() );
}

void debugandrew()
{
    pt tam[5];
    tam[0] = pt(1,1);
    tam[1] = {3,1}, tam[2] = {2,1}, tam[3] = {2,0}, tam[4] = {2,2};
    vector<pt> C;
    andrew(C,tam+3,tam+4);
    for(pt &p : C) p.show();
    andrew(C,tam,tam+4);
    for(pt &p : C) p.show();
}
}
using namespace geo;

int n;
pii match[mx];
pt tam[mx * 3], tmp[mx * 3];

void dnc(pt* s, pt* e)
{
    //printf("dnc on %d %d\n",s-tam,e-tam);
    if(s >= e) return;
    vector<pt> ch;
    andrew(ch,s,e);

    /*
    for(pt &p : ch){
        p.show();
        //printf("%d\n",p.c);
    }
    */
    int id=0;
    for(; id<ch.size(); id++)
    {
        if(ch[id].c == 2) break;
    }
    if(id == ch.size())
    {
        //printf("no blue in convex hull\n");
        pt *t;
        sort(s+1,e+1,[s](pt &u, pt &v)
        {
            int V = ccw(*s,u,v);
            return V ? V > 0 : d(*s,u) < d(*s,v);
        });
        int score = 0;

        PART:
        pt *u = nullptr, *v = nullptr;
        //unordered_map<int,pt*> U;
        for(t = s; t != (e+1); t++)
        {
            //printf("%d th point : ",t-s); t->show();
            score += t->c;
            //printf("score = %d\n",score);
            if(score == 0 && !u)
            {
                u = t;
                break;
            }
            //U[score] = t;
        }
        if(u != e){
            dnc(s,u);
            dnc(u+1,e);
        }
        else{
            reverse(s+1, e+1);
            goto PART;
        }
    }
    else
    {
        //printf("blue detected on convex hull\n");
        pt *t;
        for(t = s; t != (e+1); t++)
        {
            if(*t == ch[id]) break;
        }
        swap(*s,*t);
        sort(s+1,e+1,[s](pt &u, pt &v)
        {
            int V = ccw(*s,u,v);
            return V ? V > 0 : d(*s,u) < d(*s,v);
        });
        int score = 0;
        pt *u = nullptr, *v = nullptr;
        for(t = s; t != (e+1); t++)
        {
            score += t -> c;
            if(score == 1 && t -> c == -1 && !u) u = t;
            if(score == 0 && t -> c == -1 && u && !v)
            {
                v = t;
                break;
            }
        }
        match[s->i] = {u->i,v->i};
        dnc(s+1,u-1);
        dnc(u+1,v-1);
        dnc(v+1,e);
    }
}

void init()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> tam[i].x >> tam[i].y;
        tam[i].i = i;
        tam[i].c = 2;
        match[i] = {-1,-1};
    }
    for(int i=n; i<3*n; i++)
    {
        cin >> tam[i].x >> tam[i].y;
        tam[i].i = i - n + 1;
        tam[i].c = -1;
    }
}

int main()
{
    //freopen("sample.txt","rt",stdin);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    dnc(tam,tam+3*n-1);
    for(int i=0; i<n; i++)
    {
        cout << match[i].first << ' ' << match[i].second << '\n';
    }
}
