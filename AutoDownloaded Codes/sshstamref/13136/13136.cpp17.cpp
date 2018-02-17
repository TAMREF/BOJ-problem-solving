#include <iostream>
using namespace std;
typedef long long ll;
int main(){
    ll r,c,n;
    cin>>r>>c>>n;
    cout << ((r+n-1)/n) * ((c+n-1)/n) << endl;
}