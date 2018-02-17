#include <bits/stdc++.h>
using namespace std;

int mem[31][2][1500];
unordered_map<string, int> smap;
vector<string> dict;
string S[50];

int n, m;

bool check(string u, string v, int k){
    for(int i=0;i<k;i++){
        if(u[i] != v[v.size()-1-i]) return false;
    }
    return true;
}

int call_count;
int solve(int L, int rev, string tail){
    int num = smap[tail];
    int& rf = mem[L][rev][num];
    if(rf != -1) return rf;

    //++call_count;if(call_count % 1000 == 0) cout << call_count << endl;

    if(!L){
        return rf = check(tail,tail,(tail.size()+1)/2);
    }

    int dp = 0;

    if(tail.size() > L){
        int g = (tail.size() - L), h = (tail.size() + L);
        if(!rev){
            for(int i = L; i <= h / 2; i++){
                if( tail[i] != tail[tail.size()-i-1 + L]) return rf = 0;
                return rf = solve(L, rev, tail.substr(0,L));
            }
        }else{
            for(int i = 0; i < g / 2; i++){
                if(tail[i] != tail[g - 1 - i]) return rf = 0;
            }
            return rf = solve(L, rev, tail.substr(g));
        }
    }

    if(!rev){
        for(int i=0;i<n;i++){
            int mn = min(tail.size(), S[i].size());
            if(L < S[i].size()) continue;
            if(check( tail, S[i], mn )){
                if(S[i].size() <= tail.size()){
                    dp += solve(L - S[i].size(), 0, tail.substr(mn));
                }else{
                    dp += solve(L - S[i].size(), 1, S[i].substr(0, S[i].size() - mn));
                }
            }
        }
    }else{
        for(int i=0;i<n;i++){
            int mn = min(tail.size(), S[i].size());
            if(L < S[i].size()) continue;
            if(check( S[i], tail, mn )){
                if(S[i].size() < tail.size()){
                    dp += solve(L - S[i].size(), 1, tail.substr(0, tail.size() - mn));
                }else{
                    dp += solve(L - S[i].size(), 0, S[i].substr(mn));
                }
            }
        }
    }
    return rf = dp;
}

int main(){
    cin>>n>>m;
    getline(cin,S[0]);

    smap[""] = 0;
    for(int i=0;i<n;i++){
        getline(cin,S[i]);
        //cout << "S = " << S[i] << endl;
        while(!isalpha(S[i].back())) S[i].pop_back();
        for(int j=0;j<S[i].size();j++){
            dict.push_back(S[i].substr(j));
            dict.push_back(S[i].substr(0,j+1));
        }
    }
    sort(dict.begin(), dict.end());
    dict.erase(unique(dict.begin(),dict.end()),dict.end());
    for(int i=0;i<dict.size();i++){
        smap[dict[i]] = i + 1;
    }

    for(int i=0;i<31;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<1500;k++){
                mem[i][j][k] = -1;
            }
        }
    }

    mem[0][0][0] = 1;

    cout << solve(m, 0, "") << endl;
}