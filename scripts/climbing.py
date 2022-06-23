max_T=10
max_mm=100000
max_height=1000000000

n0=int(input())
n=[]
hv = []
for k in range(n0):
    tmp_n=int(input())
    n.append(tmp_n)
    hv = []
    if (2 <= tmp_n <= max_mm):
        hv_str=list(map(int, input().strip().split(' ')))

        for hv_stri in hv_str:
            tmp_hv = int(hv_stri)
            if(1 <= tmp_hv <= max_height):
                hv.append(tmp_hv)

# print(hv)
#
    wid=0
# for k in range(n0):
    min_v = max_height
    #tmp = [0, 0]
    diff = []
    for i in range(n[k]):
        for j in range(0, i):
            tmp_diff = abs(hv[i+wid] - hv[j+wid])
            diff.append(tmp_diff)
            #print(tmp_diff,end=' ')
            if (tmp_diff <= min_v):
                min_v = tmp_diff
                #tmp = [i, j]
        #print('\n')

    min_num = 0
    for i in range(len(diff)):
        if (min_v == diff[i]):
            min_num += 1

    print(min_v,min_num)
    wid=wid+n[k]

# for test
# 2
# 5
# 1 2 5 4 3
# 4
# 3 3 3 10