########### github.com/tykr0001/algorithm ###########
#*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*#
#*$*                                             *$*#
#*$*    ||||||||  ||    ||  ||   |||  |||||||    *$*#
#*$*       ||      ||  ||   || |||    ||    ||   *$*#
#*$*       ||        ||     |||       |||||||    *$*#
#*$*       ||        ||     || |||    ||  ||     *$*#
#*$*       ||        ||     ||   |||  ||   |||   *$*#
#*$*                                             *$*#
#*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*#
################ 2021-04-19 23:22:36 ################

################ PyPy3 Header Template  #############
#-*-coding:utf-8-*-
import sys
#####################################################

num = int(input())


def Convert(num, n):
    ret = ""
    while num > 0:
        remainder = num % n
        num = num // n
        ret = str(remainder) + ret
    return ret


def IsPalindrome(str):
    beg = 0
    end = len(str)-1
    while beg <= end:
        if str[beg] != str[end]:
            return False
        beg = beg + 1
        end = end - 1
    return True


def main():
    is_answer = False
    for i in range(2, 11, 1):
        str = Convert(num, i)
        if IsPalindrome(str):
            print(i, str)
            is_answer = True

    if not is_answer:
        print("NIE")


main()
