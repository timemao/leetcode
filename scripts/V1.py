arr_n=int(input())
for k in range(arr_n):
    strr = input()
    n = len(strr)
    res = 0

    i = 0
    while (i < n):
        if (strr[i] == '+' or strr[i] == '-'):
            start = i + 1
            tmp_l = 0
            while (strr[start] != '+' and strr[start] != '-'):
                tmp_l = tmp_l + 1
                start = start + 1
                if (start == n):
                    break
            tmp_n = int(strr[(i + 1):(i + 1 + tmp_l)])
            # print tmp_n
            if (strr[i] == '+'):
                res = res + tmp_n
            elif (strr[i] == '-'):
                res = res - tmp_n
            i = i + 1 + tmp_l
        else:
            start = 0
            tmp_l = 0
            while (strr[start] != '+' and strr[start] != '-'):
                tmp_l = tmp_l + 1
                start = start + 1
                if (start == n):
                    i = n
                    break
            tmp_n = int(strr[0:(tmp_l)])
            # print tmp_n
            res = tmp_n
            i = i + tmp_l

    print (res)