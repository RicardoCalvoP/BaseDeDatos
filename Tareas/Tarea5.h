#include <iostream>
#include <time.h>
using namespace std;

class nodo
{
public:
    int valor;
    nodo *siguiente;
};

class ListaLigada
{
private:
    nodo *indice;

public:
    ListaLigada();
    ~ListaLigada();
    bool ListaVacia();   // tambien se puede int
    int LongitudLista(); // Devuelve la longitud de una lista
    void InsertarFinalLista(int num);
    void EliminaLista(int num);
    void Show();

    // Funciones Tarea 5
    void InsertarInicioLista(int numero);
    void search(int numero);
    void EliminarPares();
    void Promedio();
    void EliminaNumeroLista(int num);
};

ListaLigada::ListaLigada() { indice = NULL; }

ListaLigada::~ListaLigada()
{
}

inline bool ListaLigada::ListaVacia()
{
    if (indice == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int ListaLigada::LongitudLista()
{
    nodo *temporal;
    int longitud = 0;
    temporal = indice;
    while (temporal != NULL)
    {
        longitud += 1;
        temporal = temporal->siguiente;
    }
    // cout << "Longitud de la Lista: " << longitud << "\n";
    return longitud;
}

void ListaLigada::InsertarFinalLista(int num)
{
    cout << "Nuevo elemento en la lista: " << num << "\n";
    nodo *elemento = new nodo();
    if (elemento == NULL)
    {
        cout << "No se puede crear un elemento en la lista\n";
        return;
    }
    if (ListaVacia() == 1)
    {
        elemento->valor = num;
        elemento->siguiente = indice;
        indice = elemento;
        return;
    }
    nodo *IndiceActual = indice;
    nodo *IndiceAnterior = NULL;
    while (IndiceActual != NULL)
    {
        IndiceAnterior = IndiceActual;
        IndiceActual = IndiceActual->siguiente;
    }
    elemento->valor = num;
    elemento->siguiente = NULL;
    IndiceAnterior->siguiente = elemento;
}

void ListaLigada::EliminaLista(int num)
{
    if (ListaVacia() == 1)
    {
        cout << "No se puede eliminar, la lista esta vacia\n";
        return;
    }
    nodo *IndiceActual = indice;
    nodo *IndiceAnterior = NULL;
    nodo *temporal;
    // recorrer la lista ligada
    while (IndiceActual != NULL)
    {
        if (IndiceActual->valor == num)
        {
            if (IndiceAnterior == NULL)
            {
                temporal = IndiceActual;
                indice = IndiceActual->siguiente;
                cout << "Eliminando: " << temporal->valor << "\n";
                delete temporal;
                return;
            }
            else
            {
                temporal = IndiceActual;
                cout << "Eliminando: " << temporal->valor << "\n";
                IndiceAnterior->siguiente = IndiceActual->siguiente;
                delete temporal;
                return;
            }
        }
        IndiceAnterior = IndiceActual;
        IndiceActual = IndiceActual->siguiente;
    }
}

void ListaLigada::Show()
{
    int i = 0;
    nodo *temporal;
    temporal = indice;
    cout << "Elementos en la lista ligada:\n";
    while (temporal != NULL)
    {
        cout << "Elemento [" << i << "] -> " << temporal->valor << "\n";
        temporal = temporal->siguiente;
        i += 1;
    }
}

void ListaLigada::InsertarInicioLista(int num)
{
    nodo *elemento = new nodo();
    if (elemento == NULL)
    {
        cout << "No se puede crear un elemento en la lista\n";
        return;
    }

    elemento->valor = num;
    elemento->siguiente = indice;
    indice = elemento;
}

void ListaLigada::search(int numero)
{ /*
    Busca un numero dado por el usuario y verifica que si este en la lista
    una vez verificado que este en la lista guardara la posision (es) en las cuales
    este numero es encontrado dentro de la lista
    */
    int count = 0, posision = 0;
    // Creamos una arreglo para almacenar las posiciones del numero buscado
    int Position_Array[LongitudLista()];

    nodo *temporal;
    temporal = indice;
    while (temporal != NULL)
    {
        if (temporal->valor == numero)
        {
            Position_Array[count] = posision;
            count += 1;
        }
        temporal = temporal->siguiente;
        posision += 1;
    }
    if (count == 0)
    {
        cout << "El numero " << numero << " no esta en la lista\n";
    }
    else if (count == 1)
    {
        cout << "El numero " << numero << " fue encotrado " << count << " vez en la posision " << Position_Array[0] << "\n";
    }
    else
    {
        cout << "El numero " << numero << " fue encotrado " << count << " veces en las posiciones ";
        for (int i = 0; i < count - 1; i++)
        {
            cout << "[" << Position_Array[i] << "] ";
        }
        cout << "y [" << Position_Array[count - 1] << "]\n";
    }
}

void ListaLigada::EliminarPares()
{
    /*
   Esta funcion buscará los numeros pares dentro de la lista ligada
   y elimina estos nodos
   */
    cout << "Borrando los numeros pares de la Lista...\n";
    nodo *elemento = indice;

    while (elemento != NULL)
    {

        if (elemento->valor % 2 == 0)
        {
            nodo *eliminar = elemento;
            elemento = elemento->siguiente;
            EliminaLista(eliminar->valor);
        }
        else
        {
            elemento = elemento->siguiente;
        }
    }
}

void ListaLigada::Promedio()
{ // Calcula el promedio de todos los valores dentro de nuestra lista
    float promedio = 0;
    nodo *temporal = indice;

    while (temporal != NULL)
    {
        promedio += temporal->valor;
        temporal = temporal->siguiente;
    }
    promedio /= LongitudLista();
    cout << "El promedio es: " << promedio << "\n";
}

void ListaLigada::EliminaNumeroLista(int num)
{ // Elimina todos los numeros de la lista que el ususario haya mandadocout << "Borrando los numeros pares de la Pila...\n";
    nodo *elemento = indice;

    while (elemento != NULL)
    {

        if (elemento->valor == num)
        {
            nodo *eliminar = elemento;
            elemento = elemento->siguiente;
            EliminaLista(eliminar->valor);
        }
        else
        {
            elemento = elemento->siguiente;
        }
    }
}
