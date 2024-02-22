from __future__ import division, print_function, unicode_literals
import math
import numpy as np
import matplotlib.pyplot as plt
X = np.random.rand(1000, 1)
y = 5 + 2 * X + .2*np.random.randn(1000, 1)  # noise added

# Building Xbar
one = np.ones((X.shape[0], 1))
Xbar = np.concatenate((one, X), axis=1);

print (Xbar.shape);   
# minibatch point gradient
def minigrad(w, i, rd_id, batch_size):
    true_i = rd_id[i]
    xi = Xbar[true_i : true_i + batch_size, :]
    yi = y[true_i: true_i + batch_size]
    a = np.dot(xi, w) - yi
    return (1/batch_size*xi.T.dot(a)).reshape(2,1)



def SGD(w_init, eta):
    w = [w_init]
    w_last_check = w_init
    iter_check_w = 10
    N = X.shape[0]
    count = 0
    batch_size = 50
    for it in range(10):
        # shuffle data
        rd_id = np.random.permutation(N)
        for i in range(0, N, batch_size):
            count += 1
            g = minigrad(w[-1], i, rd_id, batch_size)
            w_new = w[-1] - eta*g
            w.append(w_new)
            if count % iter_check_w == 0:
                w_this_check = w_new
                if np.linalg.norm(w_this_check - w_last_check)/len(w_init) < 1e-3:
                    return w
                w_last_check = w_this_check
    return w


w_init = np.array([[4], [3]])
w = SGD(w_init, 1)
print('Solution found by GD: w = ', w[-1])
