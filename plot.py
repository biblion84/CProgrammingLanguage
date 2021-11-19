import matplotlib.pyplot as plt
import math 

size = 10000

logn = []
for i in range(1, size):
	logn.append(i * math.log(i))

x = []
for i in range(1, size):
	x.append(i)
	
pow = []
for i in range(1, size):
	pow.append(math.pow(i, 2))


print('Try to find the 1000')

for i in range(0, size - 1):
	if (logn[i] != 0 and (pow[i] / logn[i]) >= 1000):
		print(i)
		break
	
plt.plot(logn, label='O(nlogn)')
plt.plot(x, label='O(n)')
plt.plot(pow, label='O(n²)')
plt.legend()
plt.show()