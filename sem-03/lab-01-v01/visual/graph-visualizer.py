import matplotlib.pyplot as plt
import numpy

inputFile = "Input.txt"
inputVariable = []
inputVariable = numpy.loadtxt(inputFile, unpack = True, delimiter = " ")
size = int(inputVariable[0])

x1 = []
for i in range(a):
    x1.append(i)
print("Enter file name:")
fileName = input()
f_sin = open(fileName) #значения функции 1
y_sin = []
for _ in range (a):
    y_sin.append(float(f_sin.readline()))


ax = plt.gca()
plt.plot(x1, y_sin, linestyle='-', linewidth=1, color='dodgerblue')
ax = plt.gca()
plt.show()