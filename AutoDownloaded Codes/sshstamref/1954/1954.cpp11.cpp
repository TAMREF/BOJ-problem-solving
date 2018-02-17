#include <bits/stdc++.h>
using namespace std;

int a[100], b[100], m, n;

int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i]>>b[i];
    cin>>m;
    for(int M = 101000; M ; M--){
        int sum = 0, flag = 1;
        for(int j=0;j<n;j++){
            if((M-b[j])%a[j]){
                flag = 0;
                break;
            }
            sum += (M-b[j])/a[j];
            if(sum > m){
                flag = 0;
                break;
            }
        }
        if(flag && sum == m){
            cout<<M<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}