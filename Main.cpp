#include <iostream>
#include "Tarea5.h"
using namespace std;

int main()
{
    system("cls");
    ListaDobleLigada LDL;
    LDL.InsertarInicioLista(1);
    LDL.InsertarInicioLista(2);
    LDL.InsertarInicioLista(5);
    LDL.InsertarInicioLista(4);
    LDL.InsertarInicioLista(3);
    LDL.MostrarElementosInicio();
    LDL.EliminarPares();

    return 0;
}