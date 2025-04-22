import sys
input = sys.stdin.readline

c = int(input().strip())
for i in range(c):
    n = int(input().strip())
    x_li = []
    y_li = []
    for i in range(n):
        x, y = map(int, input().split())
        x_li.append(x)
        y_li.append(y)
    x_li.sort()
    y_li.sort()

    temp_x = x_li[0]+x_li[-1]
    temp_y = y_li[0]+y_li[-1]
    is_answer = 0
    for i in range(n//2):
        if temp_x != x_li[i]+x_li[-i-1]:
            print("no")
            is_answer = 1
            break
    if is_answer == 0:
        for i in range(n//2):
            if temp_y != y_li[i]+y_li[-i-1]:
                print("no")
                is_answer = 1
                break
    if n%2 == 1:
        if temp_x != x_li[n//2] and is_answer == 0:
            print("no")
        if temp_y != y_li[n//2] and is_answer == 0:
            print("no")
    if is_answer == 0:
        print("yes")
        
    