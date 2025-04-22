n, l = map(int, input().split())
road = list(input())

blank = 0

def check_left():
    left_blank = []
    temp = 0
    start = 0
    for i in range(len(road)):
        if road[i] == "X" and temp != 0:
            left_blank.append([temp, start+1])
            temp = 0
            start = i
        elif road[i] == "X" and temp == 0: #x다음 x가 나온경우
            start = i
        else:
            temp += 1
            if i == len(road)-1:
                if start == 0:
                    left_blank.append([temp, start])
                else:
                    left_blank.append([temp, start+1])
    return left_blank

for i in range(n):
    left_blank = check_left()
    
    li = list(x[0] for x in left_blank)
    li_max = max(li)
    li_index = li.index(li_max)

    if li_max <= l-1:
        break
    else:
        road[left_blank[li_index][1]+li_max//2] = "X"

road = ''.join(road)
print(road)