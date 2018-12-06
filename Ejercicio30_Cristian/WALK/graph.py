import matplotlib
matplotlib.use("Agg")
import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt('serial.dat')
plt.hist(data,label='serial',alpha = 0.7,bins=np.linspace(0,2000,50),density=True)
data = np.loadtxt('parallel.dat')
plt.hist(data,label='parallel',alpha=0.7,bins=np.linspace(0,2000,50),density=True)
plt.legend()
plt.savefig('compare.pdf')