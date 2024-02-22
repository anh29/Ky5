import math
import numpy as np

X = np.random.rand(1000,1)
y = 7 + 3*X + np.random.randn(1000,1)

one = np.ones((X.shape[0], 1))
Xbar = np.concatenate((one,X),axis=1)

def minigrad(theta, i, rd_id, batch_size):
    true_i = rd_id[i]
    xi = Xbar[true_i : true_i + batch_size, :]
    yi = y[true_i: true_i + batch_size]
    a = np.dot(xi, theta) - yi
    return (1/batch_size*xi.T.dot(a)).reshape(2,1)


def GDMomentum(theta_init,beta,alpha, batch_size):
    theta  = [theta_init]
    v_old = np.zeros_like(theta_init)
    iter_check = 10
    count = 0;
    N = Xbar.shape[0]
    for it in range (1000):
        rd_id = np.random.permutation(N)
        for i in range(0, N, batch_size):
            count += 1
            g = minigrad(theta[-1],i, rd_id, batch_size)
            v_new = v_old*beta + alpha*g
            theta_new = theta[-1] - v_new
            theta.append(theta_new)
            v_old = v_new
            if(count % iter_check == 0):
                if np.linalg.norm(minigrad(theta_new,i=i, rd_id= rd_id, batch_size= batch_size))/len(theta_new)<1e-6:
                    return theta
    return theta

theta_init = np.array([[2], [1]])
theta_result = GDMomentum(theta_init=theta_init, beta=0.9, alpha=0.5, batch_size= 50)
print(theta_result[-1])