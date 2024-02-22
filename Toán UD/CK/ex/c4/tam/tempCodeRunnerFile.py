import math
import numpy as np

X = np.random.rand(1000, 1)
y = 5 + 2*X + .2*np.random.randn(1000, 1)

one = np.ones((X.shape[0], 1))
Xbar = np.concatenate((one, X), axis=1)


def sgrad(theta, i, rd_id):
    true_i = rd_id[i]
    xi = Xbar[true_i, :]
    yi = y[true_i]
    a = np.dot(xi, theta) - yi
    return (xi*a).reshape(2, 1)


def NAG(theta_init, beta, alpha):
    theta = [theta_init]
    v_old = np.zeros_like(theta_init)
    N = X.shape[0]
    for it in range(1000):
        rd_id = np.random.permutation(N)
        for i in range(N):
            v_new = beta*v_old + alpha * sgrad(theta[-1]-beta*v_old, i= i, rd_id= rd_id)
        theta_new = theta[-1] - v_new
        theta.append(theta_new)
        if np.linalg.norm(sgrad(theta_new, i= i, rd_id= rd_id))/len(theta_new) < 1e-3:
            break
    return theta


theta_init = np.array([[3], [1]])
theta_result = NAG(theta_init=theta_init, beta=0.9, alpha=0.5)
print(theta_result[-1])
