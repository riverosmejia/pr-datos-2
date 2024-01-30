#include <iostream>
#include <cstring>

// Declaración de la biblioteca externa
extern "C" {

    void quicksort(double lista[], int primero, int ultimo);
    void quicksort_str_char(const char* lista[], int primero, int ultimo);
}

// Definir la función de ordenamiento para números
void quicksort_numbers(double lista[], int n) {

    quicksort(lista, 0, n - 1);
}

// Definir la función de ordenamiento para strings
void quicksort_strings(const char* lista[], int n) {

    quicksort_str_char(lista, 0, n - 1);
}

    // Ejemplo de uso para números
int main() {

    double numbers[] = {5.4, 2.7, 8.1, 3.3, 1.9};
    int numbers_size = sizeof(numbers) / sizeof(numbers[0]);
    
    std::cout << "Números originales:" << std::endl;
    for (int i = 0; i < numbers_size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    quicksort_numbers(numbers, numbers_size);

    std::cout << "Números ordenados:" << std::endl;
    for (int i = 0; i < numbers_size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl << std::endl;

    // Ejemplo de uso para strings
    const char* strings[] = {"banana", "apple", "orange", "grape", "kiwi"};
    int strings_size = sizeof(strings) / sizeof(strings[0]);
    std::cout << "Cadenas originales:" << std::endl;
    for (int i = 0; i < strings_size; ++i) {
    
        std::cout << strings[i] << " ";
    
    }
    
    std::cout << std::endl;

    quicksort_strings(strings, strings_size);

    std::cout << "Cadenas ordenadas:" << std::endl;
    for (int i = 0; i < strings_size; ++i) {
        std::cout << strings[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
