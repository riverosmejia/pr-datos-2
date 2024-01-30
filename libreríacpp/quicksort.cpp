// quicksort.cpp
#include "quicksort.h"
#include "quicksort_wrap.h"
#include <cstring>


void quicksort(double lista[], int primero, int ultimo) {
    int i, j;
    double pivote;
    double temp;

    i = primero;
    j = ultimo;
    pivote = lista[(primero + ultimo) / 2];

    do {
        while (lista[i] < pivote)
            i++;
        while (lista[j] > pivote)
            j--;

        if (i <= j) {
            temp = lista[i];
            lista[i] = lista[j];
            lista[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);

    if (primero < j)
        quicksort(lista, primero, j);
    if (i < ultimo)
        quicksort(lista, i, ultimo);
}

void quicksort_str_char(const char* lista[], int primero, int ultimo) {
    // Implementación de quicksort para strings

    int i, j;
    const char* pivote;
    const char* temp;

    i = primero;
    j = ultimo;
    pivote = lista[(primero + ultimo) / 2];

    do {
        while (strcmp(lista[i], pivote) < 0)
            i++;
        while (strcmp(lista[j], pivote) > 0)
            j--;

        if (i <= j) {
            temp = lista[i];
            lista[i] = lista[j];
            lista[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);

    if (primero < j)
        quicksort_str_char(lista, primero, j);
    if (i < ultimo)
        quicksort_str_char(lista, i, ultimo);
}
