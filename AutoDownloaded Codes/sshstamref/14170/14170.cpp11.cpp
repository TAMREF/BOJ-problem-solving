#include <bits/stdc++.h>
using namespace std;
int arr[100005], n, q;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    for(int l,r;q--;){
        cin>>l>>r;
        cout<<upper_bound(arr,arr+n,r)-lower_bound(arr,arr+n,l)<<'\n';
    }
    return 0;
}