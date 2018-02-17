#include <iostream>

using namespace std;

typedef long long ll;
const int mnum = 3e6 + 15;

bool chk[mnum];
int arr[mnum];

void bp(){
    for(ll i=3;i<mnum;i+=2){
        if(!chk[i]){
            for(ll j = i * i; j < mnum ; j += i + i)
                chk[j] = true;
        }
    }
    for(ll i = 13; i < mnum ; i++){
        arr[i] = arr[i-1];
        if(!chk[i] && i % 6 == 1) ++arr[i];
    }
}

int main(){
    bp();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,n;
    for(cin>>t;t--;){
        cin >> n;
        cout << arr[3 * n + 7] << '\n';
    }
}