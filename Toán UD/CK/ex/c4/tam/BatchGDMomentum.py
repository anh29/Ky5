import math
import numpy as np

X = np.random.rand(1000,1)
y = 5 + 2*X + np.random.randn(1000,1)

one = np.ones((X.shape[0], 1))
Xbar = np.concatenate((one,X),axis=1)

def grad(theta):
    N = Xbar.shape[0]
    return 1/N * Xbar.T.dot(Xbar.dot(theta) - y)

def GDMomentum(theta_init,beta,alpha):
    theta  = [theta_init]
    v_old = np.zeros_like(theta_init)
    iter_check = 10
    count = 0
    for it in range (1000):
        count += 1
        g = grad(theta[-1])
        v_new = v_old*beta + alpha*g
        theta_new = theta[-1] - v_new
        theta.append(theta_new)
        v_old = v_new
        if(count % iter_check == 0):
            if np.linalg.norm(grad(theta_new))/len(theta_new)<1e-6:
                return theta
    return theta

theta_init = np.array([[2], [1]])
theta_result = GDMomentum(theta_init=theta_init, beta=0.9, alpha=0.5)
print(theta_result[-1])