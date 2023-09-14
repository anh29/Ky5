import numpy as np
import matplotlib.pyplot as plt

def up_sampling(x, n):
    y = np.zeros(len(x) * n)
    for i in range(len(x)):
        for j in range(n):
            if i == 0:
                y[i * n + j] = j * y[i] / n
            else:
                y[i * n + j] = x[i] + j * (x[i] - x[i - 1]) / n
    return y

def down_sampling(x, n):
    z = []
    for i in range(0, len(x), n):
        z.append(x[i])
    return np.array(z)

f0 = 30
T = 1 / f0
t = np.arange(0, T, 0.00025)
x = np.sin(2 * np.pi * f0 * t)

n = int(input('Enter n times: '))
y = up_sampling(x, n)
z = down_sampling(x, n)

plt.figure(figsize=(8, 12))

plt.subplot(3, 1, 1)
plt.stem(t, x, 'b', basefmt=" ", markerfmt="bo", linefmt="-b", use_line_collection=True)
plt.title('Original Signal')
plt.xlabel('t')
plt.ylabel('x(t)')

plt.subplot(3, 1, 2)
plt.stem(np.arange(len(y)), y, 'g', basefmt=" ", markerfmt="go", linefmt="-g", use_line_collection=True)
plt.title(f'Increase sampling rate up to {n} times')
plt.xlabel('t')
plt.ylabel('y[n]')

plt.subplot(3, 1, 3)
plt.stem(np.arange(len(z)), z, 'r', basefmt=" ", markerfmt="ro", linefmt="-r", use_line_collection=True)
plt.title(f'Decrease sampling rate down to {n} times')
plt.xlabel('t')
plt.ylabel('z[n]')

plt.tight_layout()
plt.show()
