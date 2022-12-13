#!/usr/bin/env python3

data = open("input.txt").read().strip()
lines = [line for line in data.split("\n")]

def ordered(c1,c2):
    if type(c1)==int and type(c2)==int:
        if c1 < c2:
            return -1
        elif c1 == c2:
            return 0
        else:
            return 1
    elif type(c1)==list and type(c2)==list:
        i = 0
        while i<len(c1) and i<len(c2):
            c = ordered(c1[i],c2[i])
            if c==-1 or c==1:
                return c
            i = i + 1
        if i==len(c1) and i<len(c2):
            return -1
        elif i<len(c1) and i==len(c2):
            return 1
        else:
            return 0
    elif type(c1)==int and type(c2)==list:
        return ordered([c1],c2)
    else:
        return ordered(c1,[c2])

res_2 = 1
data = data.replace("\n\n", "\n")
for idx,c in enumerate(data.split("\n")):
    c = eval(c)
    if ordered([[2]],c) >= 1:
        res_2 += 1

res_6 = 2
data = data.replace("\n\n", "\n")
for idx,c in enumerate(data.split("\n")):
    c = eval(c)
    if ordered([[6]],c) >= 1:
        res_6 += 1

print(res_2*res_6)



