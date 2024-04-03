#include <iostream>

// Definición de la estructura Elemento
struct Elemento
{
    int clave;
    // Otros miembros si los hay
};

// Definición del tipo Clave
typedef int Clave;

// Función imprimir
void imprimirArreglo(Elemento E[], int tamano)
{
    for (int i = 0; i < tamano; ++i)
    {
        std::cout << E[i].clave << " ";
    }
    std::cout << std::endl;
}

// Función extenderRegionGrande
int extenderRegionGrande(Elemento E[], Clave pivote, int vacBaja, int alto)
{
    int vacAlta, actual;
    vacAlta = vacBaja; // Suponer fracaso, clave < pivote.
    actual = alto;
    // std::cout << actual << " " << vacBaja << " " << pivote << std::endl;
    while (actual > vacBaja)
    {
        int i = 0;
        if (E[actual].clave < pivote)
        {
            E[vacBaja] = E[actual]; // Éxito.
            vacAlta = actual;
            std::cout << i << " eg " << std::endl;
            imprimirArreglo(E, 10);
            i++;
            break;
        }
        actual--; // Seguir buscando.
    }
    return vacAlta;
}

// Función extenderRegionChica
int extenderRegionChica(Elemento E[], Clave pivote, int bajo, int vacAlta)
{
    int vacBaja, actual;
    vacBaja = vacAlta; // Suponer fracaso, clave pivote.
    actual = bajo;
    while (actual < vacAlta)
    {
        // std::cout << pivote << " a " << std::endl;
        int i = 0;
        if (E[actual].clave >= pivote)
        {
            E[vacAlta] = E[actual]; // Éxito.
            vacBaja = actual;
            std::cout << i << " ec " << std::endl;
            imprimirArreglo(E, 10);
            i++;
            break;
        }
        actual++; // Seguir buscando.
    }
    return vacBaja;
}

// Función partir para Quicksort
int partir(Elemento E[], Clave pivote, int primero, int ultimo)
{
    int bajo, alto;
    bajo = primero;
    alto = ultimo;
    while (bajo < alto)
    {
        int vacAlta = extenderRegionGrande(E, pivote, bajo, alto);
        int vacBaja = extenderRegionChica(E, pivote, bajo + 1, vacAlta);
        bajo = vacAlta;
        alto = vacAlta - 1;
    }
    return bajo; // Éste es puntoPartir.
}

// Función Quicksort
void quickSort(Elemento E[], int primero, int ultimo)
{
    if (primero < ultimo)
    {
        Elemento elementoPivote = E[primero];
        Clave pivote = elementoPivote.clave;

        std::cout << "movimiento A" << std::endl;
        int puntoPartir = partir(E, pivote, primero, ultimo);
        E[puntoPartir] = elementoPivote;

        std::cout << "movimiento B" << std::endl;
        quickSort(E, primero, puntoPartir - 1);

        std::cout << "movimiento C" << std::endl;
        quickSort(E, puntoPartir + 1, ultimo);
    }
    return;
}

int main()
{
    // Tamaño del arreglo
    const int tamano = 10;

    // Arreglo de Elementos
    Elemento E[tamano];

    // Inicialización del arreglo con las claves del 10 al 1
    for (int i = 0; i < tamano; ++i)
    {
        E[i].clave = tamano - i;
    }

    // Llamada a la función Quicksort para ordenar el arreglo
    quickSort(E, 0, tamano - 1);

    // Impresión del arreglo ordenado
    std::cout << "Arreglo ordenado: ";
    imprimirArreglo(E, tamano);

    return 0;
}
