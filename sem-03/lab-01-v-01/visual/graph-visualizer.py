import matplotlib.pyplot as plt
import numpy

inputFile = "Input.txt"
inputVariable = []
inputVariable = numpy.loadtxt(inputFile, unpack = True, delimiter = " ")
size = int(inputVariable[0])

x = []
for i in range(a):
    x.append(i)
print("Enter file name:")
fileName = input()
f = open(fileName) #значения функции 1
y = []
for _ in range (a):
    y.append(float(f.readline()))

ax = plt.gca()
plt.plot(x1, y_sin, linestyle='-', linewidth=1, color='dodgerblue')
ax = plt.gca()
plt.show()