#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define MAXIMO 5
// Definimos el máximo numero de valores que tentra nuestra cola

class ColaEstatica
{
private:
    int valores[MAXIMO];
    int Frente;
    int Atras;

public:
    ColaEstatica();
    ~ColaEstatica();
    int ColaVacia();      // Tambien se puede bool
    int ColaLLena();      // Tambien se puede bool
    void Queue();         // Añade elementos a la cola
    void DeQueue();       // Elimina elementos de la cola
    void Show();          // Muestra los elementos de la cola;
    void Random(int num); // Implemetna atributos aleatoriamente
};

ColaEstatica::ColaEstatica()
{
    Frente = 0;
    Atras = 0;
}

ColaEstatica::~ColaEstatica()
{
}

inline int ColaEstatica::ColaVacia()
{
    if (Frente == Atras)
    {
        cout << "la cola esta vacia\n";
        return 1;
    }
    else
    {
        return 0;
    }
}

inline int ColaEstatica::ColaLLena()
{
    if (Atras == MAXIMO)
    {
        cout << "La cola esta llena \n";
        return 1;
    }
    else
    {
        return 0;
    }
}

void ColaEstatica::Queue()
{

    int numero = rand() % 10 + 1;
    if (ColaLLena() == 1)
    {
        return;
    }
    else
    {

        cout << "Incorporando " << numero << " a la cola\n";
        valores[Atras] = numero;
        Atras += 1;
        Show();
    }
}

void ColaEstatica::DeQueue()
{
    if (ColaVacia() == 1)
    {
        return;
    }
    else
    {
        cout << "Eliminando " << valores[Frente] << " de la cola\n";
        for (int i = 0; i < (Atras - 1); i++)
        {
            valores[i] = valores[i + 1];
        }
        Atras -= 1;
        Show();
    }
}

inline void ColaEstatica::Show()
{
    for (int i = 0; i < Atras; i++)
    {
        cout << "[" << valores[i] << "]";
    }
    cout << "\n";
}

void ColaEstatica::Random(int num)
{
    srand(time(NULL));
    for (int i = 0; i < num; i++)
    {

        int R = rand() % 2 + 1;
        switch (R)
        {
        case 1:
            Queue();
            break;

        case 2:
            DeQueue();
            break;
        }
    }
}
