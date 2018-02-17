#include <bits/stdc++.h>
using namespace std;
int main(){
    int o=0,a;
    char x;
    while(1){
        a=0; o=0;
        string s = "";
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
            x=-1;
            assert(scanf("%c",&x));
            assert('0'<=x && x<='9');
            o |= x;
            s += x;
            x -= '0';
            a += ((j&1)?x:(x*2>9?x*2-9:x*2));
            }
            char t = getchar();
            assert(t==' ' || t=='\n');
        }
        if(s == "0000000000000000"){
            return 0;
        }
        puts(a%10?"No":"Yes");
    }
}