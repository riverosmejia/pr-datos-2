#include <iostream>
#include <iomanip>

void quicksort(double A[20], int primero, int ultimo);
void escribir(double A[20], int n);

int main()
{
    int i, nro;
    double B[20];

    std::cout << "Ingrese la dimensión del arreglo: " << std::endl << std::endl;
    std::cin >> nro;

    std::cout << "ORDENAMIENTO POR EL METODO DE QUICKSORT " << std::endl << std::endl;
    std::cout << "Ingrese elementos del arreglo: " << std::endl << std::endl;

    for (i = 0; i < nro; i++)
    {
        std::cout << "B[" << i << "] = ";
        std::cin >> B[i];
    }

    std::cout << "ARREGLO ORIGINAL" << std::endl << std::endl;

    for (i = 0; i < nro; i++)
    {
        std::cout << B[i] << std::setw(5);
    }

    quicksort(B, 0, nro - 1);
    escribir(B, nro);

    return 0;
}

void quicksort(double A[20], int primero, int ultimo)
{
    int central, i, j;
    double pivote;

    central = (primero + ultimo) / 2;
    pivote = A[central];
    i = primero;
    j = ultimo;

    do
    {
        while (A[i] < pivote)
            i++;
        while (A[j] > pivote)
            j--;

        if (i <= j)
        {
            double temp;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);

    if (primero < j)
        quicksort(A, primero, j);

    if (i < ultimo)
        quicksort(A, i, ultimo);
}

void escribir(double A[20], int n)
{
    int i;
    std::cout << std::endl << "ARREGLO ASCENDENTE" << std::endl << std::endl;

    for (i = 0; i < n; i++)
    {
        std::cout << A[i] << std::setw(5);
    }

    std::cout << std::endl << std::endl;
}
