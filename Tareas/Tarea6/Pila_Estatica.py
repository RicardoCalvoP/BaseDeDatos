def pila_vacia(arr):
    if len(arr) == 0:
        return True
    else:
        return False


def push(arr, num):
    if len(arr) >= 5:
        print("La pila está llena")
    else:
        print(f"agregando: {num} a la pila")
        arr.append(num)


def pop(arr):
    if pila_vacia(arr) == True:
        print("Pila vacia, no hay elementos por eliminar")
        return
    else:
        elemento_eliminado = arr.pop()
        print(f"Eliminando {elemento_eliminado} de la pila")


def mostrarElementos(arr):
    if pila_vacia(arr) == True:
        print("No hay elementos en la pila")
        return
    print("tope")
    for x in reversed(arr):
        print(f"[{x}]")
    print("Abajo")


arr = []
push(arr, 1)
push(arr, 2)
push(arr, 3)
push(arr, 4)
push(arr, 5)
push(arr, 6)
push(arr, 4)
push(arr, 5)
push(arr, 6)
mostrarElementos(arr)
pop(arr)
pop(arr)
pop(arr)
mostrarElementos(arr)
pop(arr)
pop(arr)
pop(arr)
mostrarElementos(arr)
