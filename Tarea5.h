#include <istream>
using namespace std;

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
    ListaDobleLigada();
};

ListaDobleLigada::ListaDobleLigada()
{
    inicio = NULL;
    fin = NULL;
}