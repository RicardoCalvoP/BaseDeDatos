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
    void EliminarPares();
    void Promedio();
    void EliminaNumeroLista(int num);
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
        fin->siguiente = elemento;
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
    /*
    Busca un numero dado por el usuario y verifica que si este en la lista
    una vez verificado que este en la lista guardara la posision (es) en las cuales
    este numero es encontrado dentro de la lista
    */
    int count = 0, posision = 0;

    // Creamos una arreglo para almacenar las posiciones del numero buscado
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

void ListaDobleLigada::EliminarPares()
{
    /*
    Esta funcion buscará los numeros pares dentro de la lista ligada
    y elimina estos nodos
    */
    cout << "Borrando los numeros pares de la Pila...\n";
    nodo *elemento = inicio;
    while (elemento != NULL)
    {
        if (elemento->valor % 2 == 0)
        {
            nodo *temporal;
            if (elemento == inicio)
            {
                temporal = elemento;
                elemento = elemento->siguiente;
                inicio = elemento;
                inicio->anterior = NULL;
                cout << "Eliminando " << temporal->valor << "\n";
                delete temporal;
            }
            else if (elemento == fin)
            {
                temporal = elemento;
                elemento = elemento->anterior;
                fin = elemento;
                fin->siguiente = NULL;
                cout << "Eliminando " << temporal->valor << "\n";
                delete temporal;
            }
            else
            {
                nodo *IndiceAnterior;
                nodo *IndiceSiguiete;

                temporal = elemento;
                IndiceAnterior = elemento->anterior;
                IndiceSiguiete = elemento->siguiente;

                IndiceAnterior->siguiente = IndiceSiguiete;
                IndiceSiguiete->anterior = IndiceAnterior;
                elemento = elemento->siguiente;
                cout << "Eliminando " << temporal->valor << "\n";
                delete temporal;
            }
        }
        elemento = elemento->siguiente;
    }
    cout << "Saliendo de la funcnion\n";
}

void ListaDobleLigada::Promedio()
{
    // Calcula el promedio de todos los valores dentro de nuestra lista
    float promedio = 0;
    nodo *temporal = inicio;

    while (temporal != NULL)
    {
        promedio += temporal->valor;
        temporal = temporal->siguiente;
    }
    promedio = promedio / LongitudLista();
    cout << "El promedio es: " << promedio << "\n";
}

void ListaDobleLigada::EliminaNumeroLista(int num)
{

    // Elimina todos los numeros de la lista que el ususario haya mandado
    nodo *temporal = inicio;
    while (temporal != NULL)
    {
        if (temporal->valor == num)
        {
            nodo *eliminar;
            if (temporal == inicio)
            {
                eliminar = temporal;
                temporal = temporal->siguiente;
                inicio = temporal;
                inicio->anterior = NULL;
                delete eliminar;
            }
            else if (temporal == fin)
            {
                eliminar = temporal;
                fin = temporal->anterior;
                temporal = temporal->siguiente;
                fin->siguiente = NULL;
                delete eliminar;
            }

            temporal = temporal->siguiente;
        }
    }
}