import numpy as np
import random

#2.1 Random Die Throw to 100 points

conteo = []
for i in range(100):
    points = 0
    count = 0
    while points < 100:
        roll = random.randint(1,6)
        points += roll
        count += 1
    conteo.append(count)

promedio = sum(conteo)/len(conteo)

print(promedio)

#2.2 Define a distance function

a = [1,5]
b = [2,2]
def distance(x,y):
    ssum = []
    for i in range(len(x)):
        ssum.append((x[i] - y[i])**2)
        print(ssum)
    sqrts = np.sqrt(sum(ssum))
    return(sqrts)

print(distance(a, b))

#2.3 Define a class Vector3D with attributes x,y,z and a method called dot that computes the dot product a the vector with another

class Vector3D:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z
    def dot(self, v):
        dot = self.x * v.x + self.y * v.y + self.z * v.z
        return dot
A = Vector3D(2,0,1)
B = Vector3D(1,-1,3)

print(A.dot(B))

#use random.shuffle to shuffle a  list
import random

a = [1,2,3,4,5,6,7,8,9]
print(a)
random.shuffle(a)
print (a)
