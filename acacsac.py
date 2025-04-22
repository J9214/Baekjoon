num = int(input())
a = 2
while num > 2:
    if num % a == 0:
        num = num//a
        print(a)        
    else:
        a += 1