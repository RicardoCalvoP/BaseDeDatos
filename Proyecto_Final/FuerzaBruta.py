import os
import string


def imprimir_tablero(tablero):
    for fila in tablero:
        print(" ".join(str(casilla) for casilla in fila))


def crear_tablero(size):
    tablero = []
    # Crea la lista de letras de 'a' a 'z'
    letras = [' '] + list(string.ascii_lowercase)[:size]
    if (size < 27):
        for i in range(size + 1):
            fila = []
            for j in range(size + 1):
                if (j == 0):
                    if (i == 0):
                        fila.append("  ")
                    else:
                        if ((size + 1 - i) < 10):
                            fila.append(str(size + 1 - i) + " ")
                        else:
                            fila.append(size + 1 - i)
                elif (i == 0):
                    fila.append(letras[j])
                else:
                    fila.append("o")
            tablero.append(fila)
        print(f"Tablero de {size} x {size} correctamente")

        imprimir_tablero(tablero)
        return tablero
    else:
        print("No se ha podido crear el tablero")
        print("Intente con un tablero con tamaño menoe a 27")


def validar_Posicion(tablero):
    print(tablero)


os.system("cls")
crear_tablero(20)
