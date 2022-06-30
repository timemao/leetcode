import numpy as np

def ti_qishuiping():
    n = input()
    n = int(n)
    s = 0
    k=3

    # s=40//2
    # n=40//2
    # k=2

    l=n
    while (n > 1):
        m = n // k
        l = n % k
        n = l + m
        s = s + m
        print("m=", m)
        if (n == k-1):  # 可以借老板一个
            s = s + 1
            break
    print(s)

def sort_maopao(list_):
    n = len(list_)
    # print("#--------- order -----------#")
    for i in range(n):
        min_v = list_[i]
        for j in range(i, n):
            if (list_[j] < min_v):
                min_v = list_[j]

                tmp = list_[j]
                list_[j] = list_[i]
                list_[i] = tmp
    return list_
def sort_tong(list_=[],is_del_repeat=0):
    #list_=[5,3,1,0,1,0,-1,-3,-3,-8]

    #n_max=10+1
    n_max=1000+1
    tong_zheng=[0]*n_max
    tong_fu=[0]*n_max

    for i in list_:
        if(i<0):
            tong_=tong_fu
            i=abs(i)
        else:
            tong_=tong_zheng

        if(tong_[i]!=0):
            if(is_del_repeat):
                tong_[i]=1
            else:
                tong_[i]=tong_[i]+1
        else:
            tong_[i]=1

    list_=[]
    tong_=tong_fu
    for i in range(n_max-1,0,-1):
        if(tong_[i]!=0):
            for j in range(abs(tong_[i])):
                list_.append(-i)
    tong_=tong_zheng
    for i in range(n_max):
        if(tong_[i]!=0):
            for j in range(abs(tong_[i])):
                list_.append(i)
    print(list_)
    return list_

def ti_mingmingsuijishu():
    # 去重+排序 = 桶排序
    lists=[]
    list=[]
    n_str=input()
    n=int(n_str)
    while(n_str!=""):
        for i in range(n):
            tmp=input()
            tmp_val = int(tmp)
            list.append(tmp_val)
        lists.append(list)
        list=[]
        n_str=input()
        if(n_str!=""):
            n=int(n_str)

    # list=[5,9,10,1,1,2,3,5,5,5,8,9]
    # list=[3,2,2,1,11,10,20,40,32,67,40,20,89,300,400,15]
    #print(list)
    list_out=[]
    for list in lists:
        # list_ = []
        # for m in list:
        #     if (m not in list_):
        #         list_.append(m)
        #list_ = sort_maopao(list_)

        list_=sort_tong(list,is_del_repeat=1)
        #print(list_)
        list_out.append(list_)
    print(list_out)

def ti_jinzhizhuanhuan():
    num_16=str(input())
    n=len(num_16)
    s=0
    base=1
    table=dict()
    for i in range(10):
        table[str(i)]=i
    table['a']=10
    table['b']=11
    table['c']=12
    table['d']=13
    table['e']=14
    table['f']=15
    table['A']=10
    table['B']=11
    table['C']=12
    table['D']=13
    table['E']=14
    table['F']=15
    for i in range(n):
        tmp= num_16[n-i-1]
        if(tmp=='x'):
            break
        s=s+base*table[tmp]
        base = base * 16
    print(s)

if __name__=="__main__":
    #ti_qishuiping()
    ti_mingmingsuijishu()
    #sort_tong()
    #ti_jinzhizhuanhuan()