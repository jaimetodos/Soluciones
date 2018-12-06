import numpy as np 
import matplotlib.pyplot as plt 

datos = np.loadtxt('data.txt')

# Esto da la integral analitica
def integral_analitica():
    return 25

# la segunda col de los datos corresponde a la integral numerica
integral_numerica = datos[:,1]

# genero puntos asociados a cada valor de N en el espacio logaritmico
puntos = np.int_(np.logspace(3,8,datos.shape[0]))

# calculo el error porcentual para cada valor de N fijo 
error = np.ones(datos.shape[0]) 
for i in range(datos.shape[0]):
    error[i] =  (np.abs((integral_analitica()-integral_numerica[i])/integral_analitica())*100)

# Plot
plt.plot(error)
plt.loglog()
plt.xlabel("$N_{puntos}$")
plt.ylabel("Error Porcentual")
plt.savefig("Error Porcentual Integral")
# plt.show()

