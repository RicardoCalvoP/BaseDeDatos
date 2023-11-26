import random as random
import string
import os


def resolverNreinas(size):
    tablero = crear_tablero(size)
    num_soluciones = 0
    colocar_reinas(tablero, 0, size, num_soluciones)
    print(f"Se encontraron {num_soluciones} soluciones para {size} reinas.")


def crear_tablero(size):
    tablero = [['o' for _ in range(size)] for _ in range(size)]
    return tablero


def imprimir_tablero(tablero):
    for fila in tablero:
        print(' '.join(fila))


def es_seguro(tablero, fila, columna, size):
    for i in range(fila):
        if tablero[i][columna] == 'Q':
            return False

        for j in range(columna, size):
            if tablero[i][j] == 'Q' and i + j == fila + columna:
                return False

            if tablero[i][j] == 'Q' and i - j == fila - columna:
                return False

            if tablero[i][j] == 'Q' and i - j == fila - columna:
                return False

    return True


def colocar_reinas(tablero, fila, size, num_soluciones):
    if fila == size:
        num_soluciones = num_soluciones + 1
        print(f"Solución #{num_soluciones}")
        imprimir_tablero(tablero)
        return num_soluciones

    for columna in range(size):
        if es_seguro(tablero, fila, columna, size):
            tablero[fila][columna] = 'Q'
            colocar_reinas(tablero, fila + 1, size, num_soluciones)
            tablero[fila][columna] = 'o'


os.system("cls")
resolverNreinas(8)  # Cambia el número de reinas aquí
