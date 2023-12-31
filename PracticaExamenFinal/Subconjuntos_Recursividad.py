import os


def existe_subconjunto_suma(lista, objetivo, indice=0, subconjunto_actual=[]):
    if objetivo == 0:
        # print("Subconjunto con la suma deseada:", subconjunto_actual)
        return True
    if indice >= len(lista) or objetivo < 0:
        return False

    # Incluir el elemento actual en el subconjunto
    incluir = existe_subconjunto_suma(
        lista, objetivo - lista[indice], indice + 1, subconjunto_actual + [lista[indice]])

    # Excluir el elemento actual del subconjunto
    excluir = existe_subconjunto_suma(
        lista, objetivo, indice + 1, subconjunto_actual)

    return incluir or excluir


os.system("cls")
# Ejemplo de uso con input para el objetivo
numeros = [1, 1, 1, 2, 3, 5, 7, 8]
posible = True
objetivo_usuario = 0
print(f"Números a analizar: {numeros}")
while (posible):
    # objetivo_usuario = int(input("Ingrese el número objetivo a buscar en los subconjuntos: "))

    if existe_subconjunto_suma(numeros, objetivo_usuario):
        print(f"Sí hay un subconjunto con suma igual a {objetivo_usuario}")
        objetivo_usuario += 1
    else:
        print(f"No hay un subconjunto con suma igual a {objetivo_usuario}")
        posible = False
