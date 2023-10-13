#include <iostream>
#include <time.h>
using namespace std;

class nodo
{
public:
    int valor;
    nodo *siguiente;
};

class ColaDinamica
{
private:
    nodo *Frente;
    nodo *Atras;

public:
    ColaDinamica();
    ~ColaDinamica();
    int ColaVacia(); // tambien se puede bool
    void queue();    // agregar elementos
    void dequeue();  // elimina elementos
    void Show();     // muestra los elementos
    void Random(int num);
};

ColaDinamica::ColaDinamica()
{
    Frente = NULL;
    Atras = NULL;
}

ColaDinamica::~ColaDinamica()
{
}

inline int ColaDinamica::ColaVacia()
{
    if (Frente == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void ColaDinamica::queue()

{
    int numero = rand() % 10 + 1;
    cout << "Agregando " << numero << " a la cola\n";
    nodo *elemento;
    elemento = new nodo();
    // se adjunta el nodo a la cola
    elemento->valor = numero;
    elemento->siguiente = NULL;
    if (ColaVacia() == 1)
    {
        Frente = elemento;
        Atras = elemento;
    }
    else
    {
        Atras->siguiente = elemento;
        Atras = elemento;
    }
    Show();
}

void ColaDinamica::dequeue()
{
    if (ColaVacia() == 1)
    {
        cout << "La cola esta vacia \n";
        return;
    }
    else
    {
        nodo *temporal;
        temporal = Frente;
        if (Frente == Atras)
        {
            Frente = NULL;
            Atras = NULL;
        }
        else
        {
            Frente = Frente->siguiente;
        }
        cout << "Eliminando de la cola: " << temporal->valor << "\n";
        delete temporal;
        Show();
    }
}

inline void ColaDinamica::Show()
{
    int i = 1;
    nodo *temporal;
    temporal = Frente;
    cout << "Elementos en la cola\n";
    while (temporal != NULL)
    {
        cout << "Elemento [" << i << "] -> " << temporal->valor << "\n";
        temporal = temporal->siguiente;
        i++;
    }
}
void ColaDinamica::Random(int num)
{
    srand(time(NULL));
    for (int i = 0; i < num; i++)
    {

        int R = rand() % 2 + 1;
        switch (R)
        {
        case 1:
            queue();
            break;

        case 2:
            dequeue();
            break;
        }
    }
}
