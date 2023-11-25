import random as random
import time as time
import string
import os

def crear_tablero(size):
    tablero = []
    # Crea la lista de letras de 'a' a 'z'
    letras = [' '] + list(string.ascii_lowercase)[:size]
    if (size < 27):
        for fila in range(size + 1):
            linea = []
            for columna in range(size + 1):
                if (columna == 0):
                    if (fila == 0):
                        linea.append("  ")
                    else:
                        if ((size + 1 - fila) < 10):
                            linea.append("0"+str(size + 1 - fila))
                        else:
                            linea.append(size + 1 - fila)
                elif (fila == 0):
                    linea.append(letras[columna])
                else:
                    linea.append("o")
            tablero.append(linea)
        print(f"Tablero de {size} x {size} creado correctamente\n")

        imprimir_tablero(tablero)
        return tablero
    else:
        print("No se ha podido crear el tablero")
        print("Intente con un tablero con tamaño menoe a 27")

def seguro(tablero, fila, columna, size):
    for i in range(fila):
        if tablero[i][columna] == 'Q':
            return False

def imprimir_tablero(tablero):
    for linea in tablero:
        print(" ".join(str(casilla) for casilla in linea))


os.system("cls")
crear_tablero(8)
