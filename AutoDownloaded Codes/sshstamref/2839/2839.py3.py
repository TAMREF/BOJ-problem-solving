n=int(input());k=9999;exec('for x in range(n//3+1):\n\tif(n-3*x)%5==0:k=min(k,x+(n-3*x)//5)\nprint(-1if k==9999 else k)')
