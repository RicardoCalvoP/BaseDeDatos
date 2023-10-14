#include <iostream>
#include "Tareas/Tarea5.h"
using namespace std;

int main()
{
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
    LL.EliminaNumeroLista(3);
    LL.Show();
    return 0;
}