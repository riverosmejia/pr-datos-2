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

void quicksort_pair_str_char(const char* nombres[], const char* tipos[], int primero, int ultimo) {
    // Implementación de quicksort para pares de strings

    int i, j;
    const char* pivote_nombre;
    const char* pivote_tipo;
    const char* temp_nombre;
    const char* temp_tipo;

    i = primero;
    j = ultimo;
    pivote_nombre = nombres[(primero + ultimo) / 2];
    pivote_tipo = tipos[(primero + ultimo) / 2];

    do {
        while (strcmp(nombres[i], pivote_nombre) < 0 || (strcmp(nombres[i], pivote_nombre) == 0 && strcmp(tipos[i], pivote_tipo) < 0))
            i++;
        while (strcmp(nombres[j], pivote_nombre) > 0 || (strcmp(nombres[j], pivote_nombre) == 0 && strcmp(tipos[j], pivote_tipo) > 0))
            j--;

        if (i <= j) {
            temp_nombre = nombres[i];
            temp_tipo = tipos[i];
            nombres[i] = nombres[j];
            tipos[i] = tipos[j];
            nombres[j] = temp_nombre;
            tipos[j] = temp_tipo;
            i++;
            j--;
        }
    } while (i <= j);

    if (primero < j)
        quicksort_pair_str_char(nombres, tipos, primero, j);
    if (i < ultimo)
        quicksort_pair_str_char(nombres, tipos, i, ultimo);
}