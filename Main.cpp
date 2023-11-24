#include <iostream>
#include "Tareas/Tarea5.h"
using namespace std;

int main()
{
    /*
    Funciones tarea 5
    LL.InsertarInicioLista(int numero);
    ll.search(int numero);
    ll.EliminarPares();
    ll.Promedio();
    ll.EliminaNumeroLista(int num);
    */
    system("cls");
    ListaLigada LL;
    LL.InsertarInicioLista(3);
    LL.InsertarInicioLista(2);
    LL.InsertarInicioLista(1);
    LL.InsertarInicioLista(3);
    LL.InsertarInicioLista(6);
    LL.InsertarInicioLista(1);
    LL.InsertarInicioLista(3);
    LL.InsertarInicioLista(10);
    LL.InsertarInicioLista(4);
    LL.InsertarInicioLista(1);
    LL.Show();
    LL.EliminaNumeroLista(3);
    LL.Show();

    return 0;
}
