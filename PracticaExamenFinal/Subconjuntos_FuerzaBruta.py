import os


def obtener_subconjuntos(lista):
    subconjuntos = []  # Almacenará todos los subconjuntos generados

    # Iterar sobre todos los posibles valores binarios de 0 a 2^n - 1
    for i in range(2 ** len(lista)):
        subconjunto = []  # Almacenará cada subconjunto en cada iteración

        # Para cada bit en la representación binaria de 'i'
        for j in range(len(lista)):
            # Verificar si el bit 'j' está encendido en 'i'
            if i & (1 << j):
                # Agregar el elemento a este subconjunto
                subconjunto.append(lista[j])

        # Agregar el subconjunto generado a la lista de subconjuntos
        subconjuntos.append(subconjunto)

    return subconjuntos


def SolSubconjuntos():
    size = int(input("Indique el tamaño de la lista: "))
    total_subconjuntos = 2**size
    lista = CrearLista(size)
    print(lista)

    # Obtener todos los subconjuntos posibles
    Subconjuntos = obtener_subconjuntos(lista)
    for index in range(total_subconjuntos):
        print(f"Subconjunto {index + 1}: {Subconjuntos[index]}")


def CrearLista(size):
    lista = []
    for i in range(size):
        lista.append(i+1)
    return lista


os.system("cls")
SolSubconjuntos()
