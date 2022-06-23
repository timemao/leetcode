hs = ['A', 'B', 'C', 'D']
ds = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K']

d_sum = sum([i for i in range(52)])

d = {}

for i in range(len(hs)):
    for j in range(len(ds)):
        d[hs[i] + ds[j]] = i * 13 + j

arr_n=int(raw_input())

for k in range(arr_n):
    strr = raw_input()
    strr = strr.split(' ')

    input_sum = 0

    for i in strr:
        if i == '':
            continue
        input_sum += d[i]

    res = d_sum - input_sum

    print hs[res // 13] + ds[res % 13]


