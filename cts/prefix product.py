def helper(a):
    n = len(a)
    l = [1]*n
    r = [1]*n
    res = [0]*n
    for i in range(1, n, 1):
        l[i] = l[i-1]*a[i-1]
    for i in range(n-2, -1, -1):
        r[i] = r[i+1]*a[i+1]
    for i in range(n):
        res[i] = l[i]*r[i]
    
    return res



t = int(input())
for _ in range(t):
    a = list(map(int, input().split()))
    b = helper(a)
    print(*b)
