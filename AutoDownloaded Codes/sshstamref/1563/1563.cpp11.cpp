#include <iostream>
const int MOD = 1000000;
int O=1, L=1, A=1, AA, LO,LA,LAA,N,tmp[7];
int main()
{
    for(std::cin>>N;--N;)
    {
        tmp[0]=O+A+AA;
        tmp[1]=O+A+AA;
        tmp[2]=O;
        tmp[3]=A;
        tmp[4]=L+LO+LA+LAA;
        tmp[5]=L+LO;
        tmp[6]=LA;
        for(int i=0;i<7;i++) tmp[i]%=MOD;
        O=tmp[0], L=tmp[1], A=tmp[2], AA=tmp[3], LO=tmp[4], LA=tmp[5], LAA=tmp[6];
    }
    std::cout<<(O+L+A+AA+LO+LA+LAA)%MOD<<std::endl;
}
