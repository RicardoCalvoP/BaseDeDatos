#include <iostream>
using namespace std;

class nodo
{
public:
    int valor;
    nodo *siguiente;
    nodo *anterior;
};

class ListaDobleLigada
{
private:
    nodo *inicio;
    nodo *fin;

public:
    ListaDobleLigada();
    // Consultar si la lista no tiene algun nodo integrado
    bool ListaVacia();
    // Consultar la longitud de la lista
    int LongitudLista();
    // Insertar Elementos al Final de la lista
    void InsertaFinalLista(int num);
    // Insertar Elementos al Inicio de la lista
    void InsertaInicioLista(int num);
};

ListaDobleLigada::ListaDobleLigada()
{
    inicio = NULL;
    fin = NULL;
}

inline bool ListaDobleLigada::ListaVacia()
{
    if (inicio == NULL && fin == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int ListaDobleLigada::LongitudLista()
{
    nodo *temporal;
    int longitud;
    temporal = inicio;
    while (temporal != NULL)
    {
        longitud += 1;
        temporal = temporal->siguiente;
    }
    return longitud;
}

void ListaDobleLigada::InsertaFinalLista(int num)
{
    cout << "Nuevo eleento en el final de la lista: " << num << "\n";
    nodo *elemento = new nodo();
    if (elemento == NULL)
    {
        cout << "No se puede crear un elemento en la lista\n";
        return;
    }
    if (ListaVacia() == true)
    {
        elemento->valor = num;
        elemento->anterior = NULL;
        elemento->siguiente = NULL;
        inicio = elemento;
        fin = elemento;
    }
    else
    {
        elemento->valor = num;
        elemento->siguiente = NULL;
        elemento->anterior = fin;
        fin->siguiente = elemento;
        fin = elemento;
    }
}

void ListaDobleLigada::InsertaInicioLista(int num)
{
}
