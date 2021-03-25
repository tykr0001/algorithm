import sys
input=sys.stdin.readline
#dict �� ������ ������ ��Ÿ��
only_A_element=1
only_B_element=2
intersection_A_and_B=3


A=[]     #A���� ����
B=[]     #B���� ����
print('A������ ���� 1~100������ ������ �ߺ� ���� �Է����ּ���.(�Է��� ��ġ�� �ʹٸ� 0�� �������� �Է�)')
while True:     #A���� ���� �Է�
    A.extend(list(map(int,input().split())))
    if A[-1]==0:
        A.pop()      #0�� A������ ���Ұ� �ƴ����� ������.
        break
print('B������ ���� 1~100������ ������ �ߺ� ���� �Է����ּ���.(�Է��� ��ġ�� �ʹٸ� 0�� �������� �Է�)')
while True:          #B���� ���� �Է�
    B.extend(list(map(int,input().split())))
    if B[-1]==0:
        B.pop()      #0�� B������ ���Ұ� �ƴ����� ������.
        break


print()

operation_set={}                        #���� dict�� ���� 1�̸� A���� ���� 2�� B���� ���� 3�̸� ��� �����̴�.
for i in A:
    operation_set[i]=only_A_element     #A�� ���Ҷ�� ���� operation_set�� ǥ���� �ش�.

for i in B:
    if i in operation_set:
        operation_set[i]=intersection_A_and_B #A���� �ִ� ���� ���ٸ� operation_set�� ���� ���� ���Ҷ�� ���� ��Ÿ���ش�.
    else:
        operation_set[i]=only_B_element       #A�� ���� ���Ҷ�� operation_set�� ���� B�� ���Ҷ�� ǥ���Ѵ�.

Union=list(map(str,operation_set.keys()))     #Keys ���� ���� ��ȯ�Ͽ� Union�� �����. ���� ������� ���ؼ� str�� �ִ´�.
Intersection=[]  #A�� B�� ������
A_relative=[]    #A-B
B_relative=[]    #B-A
for i,j in operation_set.items():    #Keys �� value�� ��ι޴´�.
    if j==only_A_element:            #value�� only_A_element�� A���� �ִ� ���� �̹Ƿ� A_relative�� �ִ´�.
        A_relative.append(str(i))
    elif j==only_B_element:          #value�� only_B_element�� B���� �ִ� ���� �̹Ƿ� B_relative�� �ִ´�.
        B_relative.append(str(i))
    else:
        Intersection.append(str(i))  #value�� only_a_element�� �ƴϰ� only_B_element�� �ƴϸ� A�� B�� ��� �ִ� �����̹Ƿ� Intersection�� �ִ´�.


#������ Union,Intersection, A-B, B-A�� ����Ѵ�.
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