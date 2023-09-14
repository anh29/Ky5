import numpy as np
import matplotlib.pyplot as plt
import sounddevice as sd

A = 2
phi = np.pi / 2
n = np.arange(0, 2001)  # Create an array from 0 to 2000

F0 = 1000
Fs1 = 3 * F0
Fs2 = 1.5 * F0
Ts1 = 1 / Fs1
Ts2 = 1 / Fs2

t1 = n * Ts1
t2 = n * Ts2

x1 = A * np.cos(2 * np.pi * F0 * t1 + phi)  # Corresponding to sampling frequency Fs1
x2 = A * np.cos(2 * np.pi * F0 * t2 + phi)  # Corresponding to sampling frequency Fs2

plt.figure(figsize=(8, 6))

plt.subplot(2, 1, 1)
plt.stem(t1, x1, use_line_collection=True)
plt.title(r'$x_1(t) = A \cos(2\pi F_0 t_1 + \phi)$')
plt.xlabel(r'$t_1$ (s)')
plt.ylabel(r'$x(t_1)$')

plt.subplot(2, 1, 2)
plt.stem(t2, x2, use_line_collection=True)
plt.title(r'$x_2(t) = A \cos(2\pi F_0 t_2 + \phi)$')
plt.xlabel(r'$t_2$ (s)')
plt.ylabel(r'$x(t_2)$')

plt.tight_layout()
plt.show()

# To play the signals as audio
sd.play(x1, Fs1)
sd.wait()
sd.play(x2, Fs2)
sd.wait()
