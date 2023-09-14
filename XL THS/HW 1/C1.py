import numpy as np                
import matplotlib.pyplot as plt   
import sounddevice as sd          

# Định nghĩa các hằng số
A = 2                            
phi = np.pi / 2                  
n = np.arange(0, 2001)           

# Tạo tín hiệu
F0 = 1000                           
Fs_x1 = 2 * F0                   
Fs_x2 = 3 * F0                   

x1 = A * np.cos(np.pi * n + phi) 
x2 = A * np.cos((2/3) * np.pi * n + phi) 

# Vẽ biểu đồ của tín hiệu
plt.subplot(2, 1, 1)             
plt.stem(n, x1, use_line_collection=True) 
plt.title(r'$x_1[n] = A\cos(\pi n + \phi)$') 
plt.xlabel('n')                  
plt.ylabel('x1[n]')              

plt.subplot(2, 1, 2)             
plt.stem(n, x2, use_line_collection=True) 
plt.title(r'$x_2[n] = A\cos\left(\frac{2}{3}\pi n + \phi\right)$') 
plt.xlabel('n')                  
plt.ylabel('x2[n]')              

plt.tight_layout()               
plt.show()                       

sd.play(x1, Fs_x1)               
sd.wait()                        

sd.play(x2, Fs_x2)               
sd.wait()                        
