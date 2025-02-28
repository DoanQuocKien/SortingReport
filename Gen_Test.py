import numpy as np

def random_increasing_array(n, a, b, mode):
    arr = np.random.uniform(a, b, size=n)
    if mode == 1:
        return np.sort(arr)
    elif mode == 2:
        return np.sort(arr)[::-1]
    else:
        return arr

n = 1000000

with open("testcase.txt", "w") as f:
    arr = random_increasing_array(n, -1e9, 1e9, 1)
    np.savetxt(f, X=arr[None], delimiter=" ")
    arr = random_increasing_array(n, -1e9, 1e9, 2)
    np.savetxt(f, X=arr[None], delimiter=" ")
    for i in range(8):
        arr = random_increasing_array(n, -1e9, 1e9, 3)
        np.savetxt(f, X=arr[None], delimiter=" ")