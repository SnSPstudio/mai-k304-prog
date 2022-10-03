import matplotlib.pyplot as plt
x1 = []
for i in range(10):
    x1.append(i)
print("Enter file name:")
fileName = input()
f_sin = open(fileName) #значения функции 1
y_sin = []
for _ in range (10):
    y_sin.append(float(f_sin.readline()))


ax = plt.gca()
plt.plot(x1, y_sin, linestyle='-', linewidth=1, color='dodgerblue')
ax = plt.gca()
plt.show()