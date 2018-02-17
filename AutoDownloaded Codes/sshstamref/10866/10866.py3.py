from collections import deque as dq
D=dq([])
for _ in range(int(input())):
    a=list(input().split())
    if a[0]=="push_back": D.append(a[1])
    elif a[0]=="push_front": D.appendleft(a[1])
    elif a[0]=="pop_back": print(-1 if len(D)==0 else D.pop())
    elif a[0]=="pop_front": print(-1 if len(D)==0 else D.popleft())
    elif a[0]=="size": print(len(D))
    elif a[0]=="empty": print(1 if len(D)==0 else 0)
    elif a[0]=="front": print(-1 if len(D)==0 else D[0])
    else: print(-1 if len(D)==0 else D[-1])