import os
import random as random


def CrearLista(lista, size):
    for i in range(size):
        lista.append(random.randint(0, 100))
    print(f"Lista de números: {lista}")
    return size


def quickSort(Arr, left, right):
    if left < right:  # si esto es verdad significa que el arreglo contiene al menos dos elementos
        position = partition(Arr, left, right)
        quickSort(Arr, left, position - 1)
        quickSort(Arr, position + 1, right)


def partition(Arr, left, right):
    i = left
    j = right - 1
    pivot = Arr[right]
    # print(f"pivot: {pivot}")

    while i < j:
        while i < right and Arr[i] < pivot:
            i += 1
        while j > left and Arr[j] >= pivot:
            j -= 1
        if i < j:
            Arr[i], Arr[j] = Arr[j], Arr[i]
            # print(Arr)

    if Arr[i] > pivot:
        Arr[i], Arr[right] = Arr[right], Arr[i]
        # print(Arr)

    return i


def SolDivide_y_Venceras():
    lista = []
    size = random.randint(3, 10)
    CrearLista(lista, size)
    quickSort(lista, 0, size-1)
    print(f"Valor mínimo: {lista[0]}")
    print(f"Valor máximo: {lista[size-1]}")


os.system("cls")
SolDivide_y_Venceras()

"""
import os
import random as random


def CrearLista(lista, size):
    for i in range(size):
        lista.append(random.randint(0, 100))
    print(f"Lista de números: {lista}")
    return size


def SolDivide_y_Venceras():
    lista = []
    size = random.randint(3, 10)
    CrearLista(lista, size)
    val_min = lista[0]
    val_max = lista[0]
    for i in range(size):
        if val_min > lista[i]:
            val_min = lista[i]
        if val_max < lista[i]:
            val_max = lista[i]
    print(f"Valor minimo: {val_min}")
    print(f"Valor máximo: {val_max}")


os.system("cls")
SolDivide_y_Venceras()

"""
