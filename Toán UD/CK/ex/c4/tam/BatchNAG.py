import math
import numpy as np

X = np.random.rand(1000, 1)
y = 5 + 2*X + np.random.randn(1000, 1)

one = np.ones((X.shape[0], 1))
Xbar = np.concatenate((one, X), axis=1)


def grad(w):
    N = Xbar.shape[0]
    return 1/N * Xbar.T.dot(Xbar.dot(w) - y)


def NAG(theta_init, beta, alpha):
    theta = [theta_init]
    v_old = np.zeros_like(theta_init)
    for it in range(1000):
        v_new = beta*v_old + alpha * grad(theta[-1]-beta*v_old)
        theta_new = theta[-1] - v_new
        theta.append(theta_new)
        if np.linalg.norm(grad(theta_new))/len(theta_new) < 1e-3:
            break
    return theta


theta_init = np.array([[3], [1]])
theta = NAG(theta_init=theta_init, beta=0.9, alpha=0.5)
print(theta[-1])
