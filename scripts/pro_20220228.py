S=str(input())
T=str(input())

# S="abcdefg"
# T="abcdef"

def min_val(a,b,c):
    min_v=a
    if(min_v>b):
        min_v=b
    if(min_v>c):
        min_v=c
    return min_v

m=len(S)
n=len(T)

dp=[[-1 for x in range(n+1)] for y in range(m+1)]
#dp=[[-1]*(n+1)]*(m+1)  # error dp[0][1]=xx ==> dp[1][1]=xx
for i in range(0,m+1):
    for j in range(0,n+1):
        if(i==0 and j==0):
            dp[i][j]=0
        elif(i==0 and j!=0):
            dp[i][j]=j
        elif(i!=0 and j==0):
            dp[i][j]=i
        else:
            if(S[i-1]==T[j-1]):
                dp[i][j]=min_val(dp[i-1][j-1],dp[i][j-1]+1,dp[i-1][j]+1)
            else:
                dp[i][j]=min_val(dp[i-1][j-1]+1,dp[i][j-1]+1,dp[i-1][j]+1)
print(dp[m][n])