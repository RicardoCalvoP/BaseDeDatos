#include <iostream>
#include <time.h>
using namespace std;

class nodo
{
public:
    int valor;
    nodo *siguiente;
};

class Subconjuntos
{
private:
    nodo *indice;
    int size;

public:
    Subconjuntos();
    ~Subconjuntos();
    void Solucionar();
    bool ListaVacia();
    void LongitudLista();
    void CrearLista();
    void AgregarElemento(int num);
    void Show();
};

Subconjuntos::Subconjuntos()
{
    indice = NULL;
    size = 0;
}

Subconjuntos::~Subconjuntos()
{
}

void Subconjuntos::Solucionar()
{
    CrearLista();
    nodo *indice;
    nodo *pivot;

    Show();
}

bool Subconjuntos::ListaVacia()
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

void Subconjuntos::LongitudLista()
{
    nodo *temporal;
    int longitud;
    temporal = indice;
    while (temporal != NULL)
    {
        longitud += 1;
        temporal = temporal->siguiente;
    }
}

void Subconjuntos::CrearLista()
{
    cout << "Indique la longitud de la lista: ";
    cin >> size;
    cout << "------------------------------\n\n";
    int num;
    for (int i = 0; i < size; i++)
    {
        num = rand() % 10 + 1;
        AgregarElemento(num);
    }
}

void Subconjuntos::AgregarElemento(int num)
{
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

void Subconjuntos::Show()
{
    int i = 0;
    nodo *temporal;
    temporal = indice;
    cout << "Lista: ";
    while (temporal != NULL)
    {
        cout << "[" << temporal->valor << "]";
        temporal = temporal->siguiente;
        i += 1;
    }
}

int main()
{
    system("cls");
    Subconjuntos S;
    S.Solucionar();

    return 0;
}