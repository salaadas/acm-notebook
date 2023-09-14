def g(n):
    return n ^ (n >> 1)

n, m = [int(x) for x in input().strip().split()]
board = [[0]*(2**m)]*(2**n)

tn = 0
tm = 0
cnt = 0
for itm in range(2**m):
    for itn in range(2**n):
        board[itn][itm] = g(cnt);
        cnt += 1

for r in board:
    for c in r:
        print(c, end=' ')
    print()
