from matplotlib import pyplot as plt
import numpy as np

'''
function: demonstrate 2-D vector space, two independent vector would span the whole 2-D space
'''

x = [1,0]
y = [0,1]
'''
x = input("input 2-D vector : ")  #1,0; 0,1
x = x.split(",")
x = [int(x[i]) for i in range(len(x))]
y = input("input 2-D vector : ")  #1,0; 0,1
y = y.split(",")
y = [int(y[i]) for i in range(len(y))]
'''
x = np.array(x)
y = np.array(y)
arr = []
N = 1000
for k in range(N):
	i = np.random.randn()  #sample from N(0，1) Gaussian Distribution
	j = np.random.randn()
	z = i*x + j*y
	arr.append(z)
	
x_list = []
y_list = []
for i in range(N):
	x_list.append(arr[i][0])
	y_list.append(arr[i][1])
plt.title("2-D vector space")
plt.xlim((-5,5))
plt.ylim((-5,5))
ax = plt.gca()
ax.scatter(x_list, y_list, c='b')

plt.show()