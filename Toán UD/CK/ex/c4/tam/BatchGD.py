from __future__ import division, print_function, unicode_literals
import math
import numpy as np
X = np.random.rand(1000, 1)
y = 5 + 2 * X + .2*np.random.randn(1000, 1)  # noise added

# Building Xbar
one = np.ones((X.shape[0], 1))
Xbar = np.concatenate((one, X), axis=1)
# a = np.array([[1, 2], [3, 4]])
# b = np.array([[5, 6]])
# print( b.T)
# print(np.concatenate((a, b.T), axis=1))

def grad(w):
    N = Xbar.shape[0]
    return 1/N * Xbar.T.dot(Xbar.dot(w) - y)


def SGD(w_init, eta):
    w = [w_init]
    w_last_check = w_init
    iter_check_w = 10
    N = X.shape[0]
    count = 0
    for it in range(1000):
        count += 1
        g = grad(w[-1])
        w_new = w[-1] - eta*g
        w.append(w_new)
        if count % iter_check_w == 0:
            w_this_check = w_new
            if np.linalg.norm(w_this_check - w_last_check)/len(w_init) < 1e-6:
                return w
            w_last_check = w_this_check
    return w


w_init = np.array([[4], [1]])
w = SGD(w_init, 1)
print('Solution found by GD: w = ', w[-1])
