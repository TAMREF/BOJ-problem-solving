#include <iostream>

using namespace std;

int main()
{
    int n,x,y,i=0;
    cin>>n>>x>>y;
    if(x>y) n=x,x=y,y=n;
    while(x < y){
        x = (x+1)>>1;
        y = (y+1)>>1;
        ++i;
    }
    cout<<i<<endl;
}
