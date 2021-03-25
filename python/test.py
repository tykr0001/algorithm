import sys
input=sys.stdin.readline
#dict 에 원소의 성질을 나타냄
only_A_element=1
only_B_element=2
intersection_A_and_B=3


A=[]     #A집합 선언
B=[]     #B집합 선언
print('A집합의 원소 1~100사이의 정수를 중복 없이 입력해주세요.(입력을 마치고 싶다면 0을 마지막에 입력)')
while True:     #A집합 원소 입력
    A.extend(list(map(int,input().split())))
    if A[-1]==0:
        A.pop()      #0은 A집합의 원소가 아님으로 뺴낸다.
        break
print('B집합의 원소 1~100사이의 정수를 중복 없이 입력해주세요.(입력을 마치고 싶다면 0을 마지막에 입력)')
while True:          #B집합 원소 입력
    B.extend(list(map(int,input().split())))
    if B[-1]==0:
        B.pop()      #0은 B집합의 원소가 아님으로 빼낸다.
        break


print()

operation_set={}                        #앞의 dict의 값이 1이면 A에만 존재 2면 B에만 존재 3이면 모두 존재이다.
for i in A:
    operation_set[i]=only_A_element     #A에 원소라는 것을 operation_set에 표기해 준다.

for i in B:
    if i in operation_set:
        operation_set[i]=intersection_A_and_B #A에도 있는 원소 였다면 operation_set에 둘의 공통 원소라는 것을 나타내준다.
    else:
        operation_set[i]=only_B_element       #A에 없는 원소라면 operation_set에 오직 B의 원소라고 표기한다.

Union=list(map(str,operation_set.keys()))     #Keys 값을 전부 반환하여 Union을 만든다. 빠른 입출력을 위해서 str로 넣는다.
Intersection=[]  #A와 B의 교집합
A_relative=[]    #A-B
B_relative=[]    #B-A
for i,j in operation_set.items():    #Keys 와 value를 모두받는다.
    if j==only_A_element:            #value가 only_A_element면 A에만 있는 원소 이므로 A_relative에 넣는다.
        A_relative.append(str(i))
    elif j==only_B_element:          #value가 only_B_element면 B에만 있는 원소 이므로 B_relative에 넣는다.
        B_relative.append(str(i))
    else:
        Intersection.append(str(i))  #value가 only_a_element도 아니고 only_B_element도 아니면 A와 B에 모두 있는 원소이므로 Intersection에 넣는다.


#각각의 Union,Intersection, A-B, B-A를 출력한다.
print("union: { ",end="")
print(", ".join(Union),end=" ")
print("}")

print("intersection: { ",end="")
print(", ".join(Intersection),end=" ")
print("}")

print("A-B: { ",end="")
print(", ".join(A_relative),end=" ")
print("}")

print("B-A: { ",end="")
print(", ".join(B_relative),end=" ")
print("}")