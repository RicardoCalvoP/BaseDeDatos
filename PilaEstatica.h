#include <iostream>
#include <time.h>
using namespace std;

#define MAXIMO 5
/*
ya que es una estructura de datos estatico
se tiene que definir un maximo numero de elementos
dentro de nuestra pila
*/

class PilaEstatica
{
private:
    int Valores[MAXIMO];
    int Tope;

public:
    PilaEstatica();
    ~PilaEstatica();
    int PilaLLena(); // tambien puede ser bool
    int PilaVacia(); // tambien puede ser bool
    void PUSH();
    void POP();
    void Show();
    void Random(int num);
};

PilaEstatica::PilaEstatica()
{
    Tope = -1;
}

PilaEstatica::~PilaEstatica()
{
}

inline int PilaEstatica::PilaLLena()
{
    if (Tope == MAXIMO - 1)
    /*
    Lo medimos como MAXIMO -1 ya que teoricamente la pila va desde el indice
    0 al indice 4
    */
    {
        cout << "La pila esta Llena \n";
        return 1;
    }
    else
    {
        return 0;
    }
}

inline int PilaEstatica::PilaVacia()
{
    if (Tope == -1)
    {
        cout << "La pila esta vacia \n";
        return 1;
    }
    else
    {
        return 0;
    }
}

void PilaEstatica::PUSH()
{

    int numero;
    numero = rand() % 10 + 1;
    if (PilaLLena() == 1)
    {
        return;
    }
    else
    {
        cout << "Agregando numero: " << numero << "\n";
        Tope++;
        Valores[Tope] = numero;
        Show();
    }
}

void PilaEstatica::POP()
{
    if (PilaVacia() == 1)
    {
        return;
    }
    else
    {
        cout << "Eliminando numero: " << Valores[Tope] << "\n";
        Valores[Tope] = 0;
        Tope--;
        Show();
    }
}

void PilaEstatica::Show()
{
    for (int i = Tope; i >= 0; i--)
    {
        cout << "[" << Valores[i] << "]\n";
    }
}
void PilaEstatica::Random(int num)
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
