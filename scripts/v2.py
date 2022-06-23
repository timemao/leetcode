arr_n=int(raw_input())

for k in range(arr_n):

    strr = raw_input()
    strr = strr.split(' ')

    n = int(strr[0])
    m = int(strr[1])

    map = []
    for i in range(n):
        map += [[1e8 for j in range(n)]]

    choose = []

    max_dist = 0
    sum_dist = 0

    max_len = 1e8
    start_index = 0
    for i in range(m):
        strr = raw_input()
        strr = strr.split(' ')
        strr = [int(elem) for elem in strr]

        map[strr[0] - 1] [strr[1] - 1] = strr[2]
        map[strr[1] - 1][strr[0] - 1] = strr[2]

        if strr[2] < max_len:
            max_len = strr[2]
            start_index = 0

    choose += [start_index]

    index = 0
    while len(choose) < n:
        i = choose[index]

        min_index = -1
        min_dist = 1e8
        for j in range(0, n):
            if map[i][j] < min_dist and j not in choose:
                min_index = j
                min_dist = map[i][j]

        if min_index != -1:
            choose += [min_index]
            if max_dist < min_dist:
                max_dist = min_dist
            sum_dist += min_dist

        index += 1

    print sum_dist, max_dist