#include <iostream>
#include <time.h>
using namespace std;

// Examen Prueba, crear una lista doblemente ligada circular

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
    ~ListaDobleLigada();
    int ListaVacia();
    int LongitudLista();
    void InsertarFinalLista(int num);
    void EliminaLista(int numero);
    void MostrarElementosInicio();
    void MostrarElementosFin();
};

ListaDobleLigada::ListaDobleLigada()
{
    inicio = NULL;
    fin = NULL;
}

ListaDobleLigada::~ListaDobleLigada()
{
}

inline int ListaDobleLigada::ListaVacia()
{
    if (inicio == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

inline int ListaDobleLigada::LongitudLista()
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

void ListaDobleLigada::InsertarFinalLista(int numero)
{
    cout << "Agregando " << numero << " al final de la lista\n";
    nodo *elemento = new nodo();
    if (elemento == NULL)
    {
        cout << "No se puede crear un elemento en la lista";
        return;
    }
    if (ListaVacia() == 1)
    {
        elemento->valor = numero;
        elemento->anterior = NULL;
        elemento->siguiente = NULL;
        inicio = elemento;
        fin = elemento;
    }
    else
    {
        inicio->anterior = elemento;
        elemento->valor = numero;
        elemento->siguiente = inicio;
        elemento->anterior = NULL;
        inicio = elemento;
    }
}

void ListaDobleLigada::EliminaLista(int num)
{
    if (ListaVacia() == 1)
    {
        cout << "La lista esta vacia\n";
        return;
    }
    else
    {
        nodo *IndiceAnterior = NULL;
        nodo *IndiceActual = inicio;
        nodo *IndiceSiguiente = inicio->siguiente;
        nodo *temporal;
        while (IndiceActual != NULL)
        {
            if (IndiceAnterior->valor == num)
            {
                if (IndiceAnterior == NULL && IndiceSiguiente == NULL)
                {
                    temporal = IndiceActual;
                    inicio = IndiceActual->siguiente;
                    inicio->anterior = NULL;
                    cout << "Eliminando: " << temporal->valor << "\n";
                    delete temporal;
                    return;
                }
            }
            else
            {
                temporal = IndiceActual;
                cout << "Eliminando: " << temporal->valor << "\n";
                if (IndiceActual == fin)
                {
                    IndiceAnterior->siguiente = NULL;
                    fin = IndiceAnterior;
                }
                else
                {
                    IndiceAnterior->siguiente = IndiceSiguiente;
                    IndiceSiguiente->anterior = IndiceActual;
                }
                delete temporal;
                return;
            }
        }
        IndiceAnterior = IndiceActual;
        IndiceActual = IndiceActual->siguiente;
        IndiceSiguiente = IndiceSiguiente->siguiente;
    }
    cout << "Elemento: " << num << " no se pudo eliminar\n";
}

void ListaDobleLigada::MostrarElementosInicio()
{
    int i = 0;
    nodo *temporal;
    temporal = inicio;
    cout << "Elementos en la lista ligada: \n";
    while (temporal != NULL)
    {
        cout << "Elemento[" << i << "] " << temporal->valor << "\n";
        temporal = temporal->siguiente;
        i += 1;
    }
}

void ListaDobleLigada::MostrarElementosFin()
{
    int i = LongitudLista();
    nodo *temporal;
    temporal = fin;
    cout << "Elemento [" << i << "] " << temporal->valor << "\n";
    temporal = temporal->anterior;
    i -= 1;
}
