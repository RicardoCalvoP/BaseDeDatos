#include <iostream>
#include "Tarea5.h"
using namespace std;

int main()
{
    system("cls");
    ListaDobleLigada LDL;
    LDL.InsertarFinalLista(1);
    LDL.InsertarFinalLista(2);
    LDL.InsertarFinalLista(5);
    LDL.InsertarFinalLista(4);
    LDL.InsertarFinalLista(3);
    LDL.InsertarFinalLista(2);
    LDL.MostrarElementosInicio();

    LDL.EliminarPares();
    LDL.MostrarElementosInicio();

    return 0;
}