import numpy as np


def distance(p,q):
    N = q.shape[0]
    D = q.shape[1]
    diff =  np.repeat(np.expand_dims(p,0),N,axis=0) - q.reshape(N,1,D)
    temp = np.matmul(diff,np.transpose(diff,[0,2,1]))
    dist = []
    for i in range(temp.shape[0]):
        dist.append(np.diag(temp[i]))

    dist = np.asarray(dist)
    dist_sorted = np.sort(dist)
    dist_sorted_idx = np.argsort(dist)

    return dist_sorted,dist_sorted_idx

def knn(pool,query,k):
    dist_sorted,dist_idx = distance(pool,query)
    grouping_points = np.repeat(np.expand_dims(pool,0),query.shape[0],axis=0)[...,dist_idx[...,:k][0],:]
    return dist_sorted[...,:k],grouping_points



q = np.random.randn(3,3)
k = np.random.randn(10,3)
knn_points = knn(k,q,3)
knn_points[0].shape,knn_points[1].shape # ((3, 3), (3, 3, 3))

knn_points = knn(k,k,3)
knn_points[0].shape,knn_points[1].shape # ((10, 3), (10, 3, 3))
