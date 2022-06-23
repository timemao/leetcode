
num=10
n0=int(input())
while (1<=num<=10 and 1<=n0<=100):
    x=0
    n=n0
    while(n>=3):
        x=x+int(n/3)
        m=int(n/3)
        n=(n-3*(int(n/3)))+(m)
    if(n==2):
        x=x+1

    print(x)

    num-=1
    n0=int(input())