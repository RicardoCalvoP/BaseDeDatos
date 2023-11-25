import random as random
import time as time
import os


def SolSubconjuntos():
    size = int(input("Indique el tamaño de la lista: "))
    lista = CrearLista(size)
    print(lista)
    Subconjuntos = []
    total_subconjuntos = 2**size
    for index in range(total_subconjuntos):
        subconjunto = []
        for pivot in range(size):
            subconjunto.append(lista[pivot])

        Subconjuntos.append(subconjunto)
        print(Subconjuntos[index])


def CrearLista(size):
    lista = []
    for i in range(size):
        lista.append(random.randint(0, 10))
    return lista


os.system("cls")
SolSubconjuntos()
