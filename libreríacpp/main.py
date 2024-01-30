from ctypes import CDLL, c_double, c_int, c_char_p

# Cargar la biblioteca
quicksort_lib = CDLL('./quicksort.so')  # Ajusta el nombre del archivo según el que hayas compilado

# Definir la función de ordenamiento para números
def quicksort_numbers(numbers):
    
    array_type = (c_double * len(numbers))(*numbers)
    quicksort_lib.quicksort(array_type, c_int(0), c_int(len(numbers) - 1))
    numbers[:] = list(array_type)

# Definir la función de ordenamiento para strings
def quicksort_strings(strings):

    array_type = (c_char_p * len(strings))()
    array_type[:] = [bytes(s, 'utf-8') for s in strings]
    quicksort_lib.quicksort_str_char(array_type, c_int(0), c_int(len(strings) - 1))
    strings[:] = [s.decode('utf-8') for s in array_type]

# Ejemplo de uso para números
numbers = [5.4, 2.7, 8.1, 3.3, 1.9]
print("Original numbers:", numbers)
quicksort_numbers(numbers)
print("Sorted numbers:", numbers)

# Ejemplo de uso para strings
strings = ["banana", "apple", "orange", "grape", "kiwi"]
print("\nOriginal strings:", strings)
quicksort_strings(strings)
print("Sorted strings:", strings)
