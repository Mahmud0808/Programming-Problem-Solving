import math
while True:
	pa = map(int, input().split())
	p, a = pa
	if p==0 and a==0:
		break;
	N = pow(a, p, p)
	n = round(math.sqrt(p)+1)
	notprime = False
	for i in range(2, n):
		if p%i==0:
			notprime = True
			break
	if notprime:
		if N==a:
			print("yes")
		else:
			print("no")
	else:
		print("no")