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
    bool ListaVacia();    // tambien se puede int
    void LongitudLista(); // Devuelve la longitud de una lista
    void InsertarFinalLista(int num);
    void EliminaLista(int num);
    void Show();
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

void ListaLigada::LongitudLista()
{
    nodo *temporal;
    int longitud;
    temporal = indice;
    while (temporal != NULL)
    {
        longitud += 1;
        temporal = temporal->siguiente;
    }
    cout << "Longitud de la Lista: " << longitud << "\n";
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
    cout << "Elemento: " << num << " no se puede eliminar\n";
}

void ListaLigada::Show()
{
    int i = 0;
    nodo *temporal;
    temporal = indice;
    cout << "Elementos en la lista ligada:\n";
    while (temporal != NULL)
    {
        cout << "Elemento [" << i << "] ->" << temporal->valor << "\n";
        temporal = temporal->siguiente;
        i += 1;
    }
}
