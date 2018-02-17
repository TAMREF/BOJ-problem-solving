module main;

import std.stdio, std.range, std.algorithm.comparison;

int[50][50] a;

void main(){
    int n, m, mn;
    char g;
    readf!"%d %d"(n,m);
    mn = min(n,m);
    foreach(i; iota(0, n)){
        readf!"%c"(g);
        foreach(j; iota(0, m)){
            readf!"%c"(g);
            a[i][j] = g - '0';
            //writef!"%d "(a[i][j]);
        }
    }
    int ans = 1;
    foreach(k; iota(mn-1, 0, -1)){
        foreach(i; iota(0, n-k)){
            foreach(j; iota(0, m-k)){
                if(a[i][j] == a[i][j+k] && a[i][j] == a[i+k][j] && a[i][j] == a[i+k][j+k]){
                    writeln( (k+1)*(k+1) );
                    return;
                }
            }
        }
    }
    writeln(1);
}
