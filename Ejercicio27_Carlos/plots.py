import matplotlib
import sys

matplotlib.use("Agg")

import matplotlib.pyplot as plt
import numpy as np

n=int(sys.argv[1]))

data=np.loadtxt('sample1.txt')

for i in range(2,n):
    name='sample'+str(i)+'.dat'
    sub_data = np.loadtxt(name)
    data=np.concatenate((data, sub_data), axis=0)

mean = data.mean()
sigma = data.std()

x = np.linspace(data.min(), data.max(), 100)
y = np.exp(-0.5 * ((x -mean)/sigma)**2) 
y = y/(np.sqrt(2.0* np.pi * sigma**2))

    plt.hist(data, alpha=0.5, bins=20, normed=True, label="Data. N={}".format(len(data)))
    plt.plot(x,y, label="Estimate. mean={:.1f} sigma={:.1f}".format(mean, sigma))
    plt.xlabel("x")
    plt.ylabel("PDF (x)")
    plt.legend(loc=2)
    plt.savefig(sample.pdf)
