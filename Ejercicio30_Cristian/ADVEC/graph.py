import matplotlib
matplotlib.use("Agg")
import numpy as np
import matplotlib.pyplot as plt


data = np.loadtxt('advecParallel.dat')
plt.plot(data[0], data[1], label='Parallel', alpha=0.5, lw=4,color = 'red')

data = np.loadtxt('advecSerial.dat')
plt.plot(data[0], data[1], label='Serial',color = 'black')

plt.legend()
plt.savefig('adveccion.pdf')
