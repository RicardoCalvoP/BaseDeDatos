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
    // Codigo visto en clase
    ListaDobleLigada();
    ~ListaDobleLigada();
    int ListaVacia();
    int LongitudLista();
    void InsertarFinalLista(int num);
    void EliminaLista(int numero);
    void MostrarElementosInicio();
    void MostrarElementosFin();

    // Funciones Tarea 5
    void InsertarInicioLista(int numero);
    void search(int numero);
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
        elemento->valor = numero;
        elemento->siguiente = NULL;
        elemento->anterior = fin;
        fin = elemento;
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

/*********FUNCIONES TAREA 5*************/

void ListaDobleLigada::InsertarInicioLista(int numero)
{
    cout << "Agregando " << numero << " al Inicio de la lista\n";
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

void ListaDobleLigada::search(int numero)
{
    int count = 0, posision = 0;
    int Position_Array[LongitudLista()];
    nodo *temporal;
    temporal = inicio;
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
