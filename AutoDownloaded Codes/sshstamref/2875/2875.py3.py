def main():
    n,m,k=list(map(int,input().split()))
    t=0
    while n+m>=k and n>=0 and m>=0:
        n-=2;m-=1;t+=1
    print(t-1 if t else 0)
main()