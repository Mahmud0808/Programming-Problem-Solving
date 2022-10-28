c = int(input())
for x in range(c):
	xyn = map(int, input().split())
	x, y, n = xyn
	z = pow(x, y, n)
	print(z)
a = input()