import numpy as np
from scipy.interpolate import interp1d
import matplotlib.pyplot as plt

def my_linspace(start, stop, num):
    if num <= 1:
        return [start]
    
    step = (stop - start) / (num - 1)
    result = [start + step * i for i in range(num)]
    return result

def up_sample(time, samples, up_rate):
    f = interp1d(time, samples, kind='linear') #Nội suy, time = Ox, samples = Oy, linear = connects data points with straight lines.
    new_time = my_linspace(time[0], time[-1], len(time) * up_rate)
    new_samples = f(new_time)
    return new_time, new_samples

def down_sample(time, samples, down_rate):
    new_time = time[::down_rate]
    new_samples = samples[::down_rate]
    return new_time, new_samples

# Define the original signal
time = np.array([0, 1, 2, 3, 4])
samples = np.array([1, 2, 3, 4, 5])
up_rate = 3
down_rate = 2

up_time, up_samples = up_sample(time, samples, up_rate)
down_time, down_samples = down_sample(time, samples, down_rate)

plt.figure(figsize=(12, 8)) #hình vẽ trống: kích thước(12,8)

# Original signal
plt.subplot(3, 1, 1) #subplot(num_rows, num_cols, plot_number), plot_number: Vị trí của subplot hiện tại trong lưới
plt.stem(time, samples, 'o-', label='Original Signal') # 'o':điểm tròn, '-':đường thẳng liền kết
plt.xlabel('Time')
plt.ylabel('Amplitude')
plt.title('Original Signal')
plt.grid(True)
plt.legend()

# Up-sampled signal
plt.subplot(3, 1, 2)
plt.stem(up_time, up_samples, 'o-', label='Up-sampled Signal')
plt.xlabel('Time')
plt.ylabel('Amplitude')
plt.title('Up-sampled Signal')
plt.grid(True)
plt.legend()

# Down-sampled signal
plt.subplot(3, 1, 3)
plt.stem(down_time, down_samples, 'o-', label='Down-sampled Signal')
plt.xlabel('Time')
plt.ylabel('Amplitude')
plt.title('Down-sampled Signal')
plt.grid(True)
plt.legend()

plt.tight_layout()
plt.show()
