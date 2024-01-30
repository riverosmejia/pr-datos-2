// quicksort_wrap.h
#include <string>

extern "C" {
    void quicksort(double lista[], int primero, int ultimo);
    void quicksort_str_char(const char* lista[], int primero, int ultimo);
}
