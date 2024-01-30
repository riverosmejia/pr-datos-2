// quicksort.h
#include <string>

extern "C" {
    void quicksort(double lista[], int primero, int ultimo);
    void quicksort_str(std::string lista[], int primero, int ultimo);
    void quicksort_pair_str_char(const char* nombres[], const char* tipos[], int primero, int ultimo);
}
