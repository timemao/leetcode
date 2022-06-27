import sys
print("python_version=",sys.version)
#print("input:")
input_strs=[]
# while(1):
#     input_str=input()
#
#     if(len(input_str)<1):
#         break
#
#     #print("input=",input_str)
#     input_strs.append(input_str)

while True:
    try:
        line = input()
    except EOFError:
        break
    input_strs.append(line)

n_input=len(input_strs)

for i in range(n_input):
    a,b=input_strs[i].split(" ")
    a=int(a)
    b=int(b)
    sum=a+b
    print(sum)
