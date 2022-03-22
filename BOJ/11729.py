import sys

n = int(input())
sequence = []

def move (num, a, b) :
    global sequence
    if num == 1: # basis condition
        sequence.append([a,b])
        return 1
    
    return move(num-1,a,6-a-b) + move(1,a,b) + move(num-1,6-a-b,b)
    
print(move(n,1,3))

for elem in sequence:
    print(elem[0], elem[1])