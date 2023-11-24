def cola_vacia(arr):
    if len(arr) == 0:
        return True
    else:
        return False


def queue(arr, num):
    if len(arr) >= 5:
        print("La Cola está llena")
    else:
        print(f"agregando: {num} a la Cola")
        arr.append(num)


def dequeue(arr):
    if cola_vacia(arr) == True:
        print("Cola vacia, no hay elementos por eliminar")
        return
    else:
        elemento_eliminado = arr.pop(0)
        print(f"Eliminando {elemento_eliminado} de la Cola")


def mostrarElementos(arr):
    if cola_vacia(arr) == True:
        print("No hay elementos en la pila")
        return
    print("Final")
    for x in reversed(arr):
        print(f"[{x}]")
    print("Inicio")


arr = []

queue(arr, 1)
queue(arr, 2)
queue(arr, 3)
queue(arr, 4)
queue(arr, 5)
queue(arr, 6)
queue(arr, 4)
queue(arr, 5)
queue(arr, 6)
mostrarElementos(arr)
dequeue(arr)
dequeue(arr)
dequeue(arr)
mostrarElementos(arr)
dequeue(arr)
dequeue(arr)
dequeue(arr)
mostrarElementos(arr)
