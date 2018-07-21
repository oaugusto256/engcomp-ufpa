import time
from random import randint

soma = 0
n = 10
f = open('arq1.txt', 'w')

for x in range(0, n):
    t_inicial = time.clock()
    
    for j in range(0, 10000000):
        nothing = (randint(0, 100))
    
    t_final = time.clock()
    
    print "O laco precisou de " + str((t_final - t_inicial)) + " segundos."
    
    soma = soma + (t_final - t_inicial)

media = soma/n;

print "\nA media e " + str(media) + " segundos."

f.close()