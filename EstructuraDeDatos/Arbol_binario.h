#include <iostream>
#include <time.h>
using namespace std;

/*Creacion de la clase básica de un elemento
en el arbol binario*/

class nodo
{
public:
    int valor;
    nodo *izquierda;
    nodo *derecha;
};

// Creacion de la clase arbol binario
class Arbol_binario
{
private:
    /* Elemento que apunta al inicio del arbol binario */
    nodo *raiz;

public:
    Arbol_binario()
    {
        raiz = NULL;
    }
    ~Arbol_binario();
    nodo *obtenerRaiz()
    {
        return raiz;
    };
    /* Para funciones se recomienda poner el
     * pegado a lo que estas buscando */
    void insertarNodo(int num);
    Arbol_binario::~Arbol_binario()
    {
    }

    void Arbol_binario::insertarNodo(int num)
    {
        // Creamos una nueva raiz/rama/hoja
        nodo *nuevo = new nodo();
        if (nuevo == NULL)
        {
            cout << "No se puede crear un elemento en el arbol\n";
            return;
        }
        // Agregamos valores a la raiz/rama/hoja
        nuevo->valor = num;
        nuevo->izquierda = NULL;
        nuevo->derecha = NULL;
        cout << "Agregando el valor " << num << " al arbol binario\n";
        // Cuando es el PRIMER elemento en el arbol
        if (raiz == NULL)
        {
            raiz = nuevo;
        }
        // Cuando ya existe uno o más elementos en el arbol
        else
        {
            // Indices para el recorrido del arbol
            nodo *anterior = NULL;
            nodo *actual = raiz;

            // Recorrido sobre la jerariquia del arbol
            while (actual != NULL)
            {
                anterior = actual;
                /* Si el valor es MENOR mandamos la
                informacion por el lado IZQUIERDA */
                if (num < actual->valor)
                {
                    actual = actual->izquierda;
                }
                /* Si el valor es MAYOR mandamos la
                informacion por el lado DERECHO */
                else
                {
                    actual = actual->derecha;
                }
            }
            /* Llegando a las hojas (final del arbol)
            insertamos los elementos */
            if (num < anterior->valor)
            {
                anterior->izquierda = nuevo;
            }
            else
            {
                anterior->derecha = nuevo;
            }
        }
    }
};
