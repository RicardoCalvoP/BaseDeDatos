#include <iostream>
#include <time.h>
using namespace std;

class nodo
{
public:
    int valor;
    nodo *siguiente;
};

class PilaDinamica
{
private:
    nodo *tope;

public:
    PilaDinamica();
    ~PilaDinamica();
    int PilaVacia(); // Tambien se puede ser bool
    void PUSH();     // Agrega elementos a la pila
    void POP();      // Elimina elementos de la pila
    void Show();     // Mostrar los elementos
    void Random(int num);
};

PilaDinamica::PilaDinamica()
{
    tope = NULL;
}

PilaDinamica::~PilaDinamica()
{
}

inline int PilaDinamica::PilaVacia()
{
    if (tope == NULL)
    {
        cout << "\nLa pila esta vacia\n";
        return 1;
    }
    else
    {
        return 0;
    }
}

void PilaDinamica::PUSH()
{
    int numero;
    numero = rand() % 10 + 1;
    cout << "\nAgregando numero: " << numero << "\n";
    nodo *elemento;
    elemento = new nodo();
    // se adjunta el nodo a la pila
    elemento->valor = numero;
    elemento->siguiente = tope;
    tope = elemento;
    Show();
}

void PilaDinamica::POP()
{
    if (PilaVacia() == 1)
    {
        return;
    }
    else
    {
        nodo *temporal;
        temporal = tope;
        tope = tope->siguiente;
        cout << "\nEliminando de la pila " << temporal->valor << "\n";
        delete temporal;
        Show();
    }
}

inline void PilaDinamica::Show()
{
    int i = 1;
    nodo *temporal;
    temporal = tope;
    cout << "Elementos en la pila: \n";
    while (temporal != NULL)
    {
        cout << "Elemento [" << i << "] -> " << temporal->valor << "\n";
        temporal = temporal->siguiente;
        i += 1;
    }
}

void PilaDinamica::Random(int num)
{
    srand(time(NULL));
    for (int i = 0; i < num; i++)
    {

        int R = rand() % 2 + 1;
        switch (R)
        {
        case 1:
            PUSH();
            break;

        case 2:
            POP();
            break;
        }
    }
}
