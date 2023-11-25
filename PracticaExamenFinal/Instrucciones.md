#Practica para Examen final
Nombre: Ricardo Alfredo Calvo Perez
Matricula: A01028889
Fecha: 24/11/2023

Periodo: 3er Semestre
Clase: Estructura de Datos


#INSTRUCCIONES

Para esta previa al examen tenemos los siguientes incisos

1. Algoritmos de fuerza bruta (20 puntos)
2. Programación recursiva (30 puntos)
3. Programacipon divide y venceras (30 puntos)
4. Análisis asintónico (20 puntos)
5. Notas de ayuda (0 puntos)

-------------------------------------------------------------------

#Algoritmos de fuerza bruta

Desarrolla un programa en el lenguaje C++ o Python usando una aproximación de fuerza bruta donde se encuentren todos los subjonjuntos posibles de un conjunto de números base. Tome como ejemplo las siguientes salidas del programa con el conjunto lista [1,2,3]

Salida:
[]
[1]
[1,2]
[3]
[1,3]
[2]
[1,2,3]

-------------------------------------------------------------------

#Programación recursiva

Desarrolle un programa en el lenguaje C++ o Python donde se resuelva el problema de suma de subconjuntos utilizados en una aproximación de recursividad. En este problema, se tiene una lista de números y se desea encontrar si existe algún subconjunto no vacio cuya suma sea igual a un valor objetivo.

Tome como ejemplo las siguientes salidas del programa con la lista [1,1,1,2,3,5,7,8]:

Numero a analizar: [1,1,1,2,3,5,7,8]
Objetivo: 10
Si hay un subconjunto con suma igual a 10

Numero a analizar: [1,1,1,2,3,5,7,8]
Objetivo: 100
No hay un subconjunto con suma igual a 100

-------------------------------------------------------------------

#Programación divide y venceras

Desarrolle un programa en el lenguaje C++ o Python en donde se obtenga el valor máximo y minimo de una lista utilizando una aproximación de divide y vencerás. Tome como ejemplo las siguientes ejecuciones del programa:

Lista de numeros: [3,1,4,1,5,9,2,6,5,3,4]
Valor minimo: 1
Valor máximo: 9

Lista de numeros: [2,5,1,1,5,6,3,1,5,8,9,2,1]
Valor mínimo: 1
Valor máximo: 9

-------------------------------------------------------------------

#Análisis asintónico

Para cada uno de los programas propuestos en las secciones anteriores, calcule la notación asintónica GENERAL y describe el cómo llegaron a una conclusión específica, tomando en cuenta las estructuras de datos existentes, así como las consecuencias de control y repetición en un lenguaje de programación especifico

-------------------------------------------------------------------

#Notas de ayuda

1. Para la sección UNO es importante mencionar que la cantidad de subconjuntos posibles que e pueden obtener en una lista de números esta dado por la expresión 2^n, donde n representa la cantidad de números en el arreglo y esta expresión incluye el conjunto vacio [] y el conjunto completo [todos los numeros]. La anterior expresión se deriva del echo que, para cada elemento en la lista, se tienen dos opciones, incluirlo o no incluirlo en un subconjunto.

2. Para la sección DOS se puede implementar una función parecida a como recorriamos un árbol binario de manera recursiva. Donde una rama se incluya uno a uno los valores a sumar y en otra rama se quiten uno a uno los valores con respecto al objetivo (al final se ve su en cualquier rama se alcanza el resultado). De igual modo este árbol también tendría una altura máxima de n y dos posibles opciones para cada rama.