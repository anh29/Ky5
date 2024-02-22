import math
import numpy as np

X = np.random.rand(1000, 1)
y = 5 + 2*X + np.random.randn(1000, 1)

one = np.ones((X.shape[0], 1))
Xbar = np.concatenate((one, X), axis=1)


def minigrad(theta, i, rd_id, batch_size):
    true_i = rd_id[i]
    xi = Xbar[true_i : true_i + batch_size, :]
    yi = y[true_i: true_i + batch_size]
    a = np.dot(xi, theta) - yi
    return (1/batch_size*xi.T.dot(a)).reshape(2,1)


def NAG(theta_init, beta, alpha, batch_size):
    theta = [theta_init]
    v_old = np.zeros_like(theta_init)
    N = Xbar.shape[0]
    for it in range(100):
        rd_id = np.random.permutation(N)
        for i in range(0, N, batch_size):
            v_new = beta*v_old + alpha * minigrad(theta[-1]-beta*v_old, i= i, rd_id= rd_id, batch_size=batch_size)
            theta_new = theta[-1] - v_new
            theta.append(theta_new)
            if np.linalg.norm(minigrad(theta_new, i= i, rd_id= rd_id, batch_size=batch_size))/len(theta_new) < 1e-3:
                break
    return theta


theta_init = np.array([[3], [1]])
theta = NAG(theta_init=theta_init, beta=0.9, alpha=0.5, batch_size=50)
print(theta[-1])
