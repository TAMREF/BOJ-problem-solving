#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    for(int f=1;f<=t;f++){
        int X, R, C, w = 0;
        cin >> X >> R >> C;
        if( X >= 7 || R * C % X || X > max(R,C) || (X+1)/2 > min(R,C) ) goto fin;
        switch(X){
        case 1:
        case 2:
            w = 1;
            break;
        case 3:
            if(min(R,C) >= 2) w = 1;
            break;
        case 4:
            if(min(R,C) >= 3) w = 1;
            break;
        case 5:
            if(min(R,C) >= 4 || max(R,C) >= 10) w = 1;
            break;
        case 6:
            if(min(R,C) >= 4 ) w = 1;
            break;
        }
        fin:
            cout << "Case #" << f << ": " << (w ? "GABRIEL" : "RICHARD") << '\n';
    }
}