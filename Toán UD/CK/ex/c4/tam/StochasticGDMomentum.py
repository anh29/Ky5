import math
import numpy as np

X = np.random.rand(1000, 1)
y = 7 + 3*X + .2*np.random.randn(1000, 1)
print (X.shape)

one = np.ones((X.shape[0], 1))
Xbar = np.concatenate((one, X), axis=1)
print (Xbar.shape)

def sgrad(theta, i, rd_id):
    true_i = rd_id[i]
    xi = Xbar[true_i, :]
    yi = y[true_i]
    a = np.dot(xi, theta) - yi
    return (xi*a).reshape(2, 1)


def GDMomentum(theta_init, beta, alpha):
    theta = [theta_init]
    v_old = np.zeros_like(theta_init)
    N = X.shape[0]
    iter_check_w = 10
    count = 0
    theta_last_check = theta_init
    for it in range(1000):
        rd_id = np.random.permutation(N)
        for i in range(N):
            g = sgrad(theta[-1], i, rd_id)
            v_new = v_old*beta + alpha*g
            theta_new = theta[-1] - v_new
            theta.append(theta_new)
            v_old = v_new
            if count % iter_check_w == 0:
                theta_this_check = theta_new
                if np.linalg.norm(sgrad(theta_new, i= i, rd_id=rd_id))/len(theta_new) < 0.0001:
                    return theta
                theta_last_check =theta_this_check
    return theta


theta_init = np.array([[4], [3]])
theta_result = GDMomentum(theta_init=theta_init, beta=0.4, alpha=0.5)
print(theta_result[-1])
