import ctypes
import csv

# llamar librería de c++
lib = ctypes.CDLL("./sorting_library.so")

# incluir la funcion quicksort_pair_str_char
lib.quicksort_pair_str_char.argtypes = [ctypes.POINTER(ctypes.c_char_p), ctypes.POINTER(ctypes.c_char_p), ctypes.c_int, ctypes.c_int]

# lectura del archivo csv
def leerCSV(file_path):
    try:
        with open(file_path, 'r', encoding='latin-1') as csvfile:
            reader = csv.reader(csvfile, delimiter=';')
            header = next(reader)  # Read the header
            data = [row for row in reader]  # Read the data
        return data
    except FileNotFoundError:
        print(f"Error: El archivo '{file_path}' no fue encontrado.")
        return None

# definir quicksort_pair_str_char
def quicksort_pair_str_char(nombres, tipos, primero, ultimo):
    lib.quicksort_pair_str_char(nombres, tipos, primero, ultimo)

# imprimir mensaje de guardado
def mensajeGuardado(file_path):
    data = leerCSV(file_path)
    if not data:
        print("Error: No se encontraron datos en el archivo CSV.")
        return

    # Convertir los datos de Python a arrays de strings de C para la librería quicksort
    nombres = (ctypes.c_char_p * len(data))()
    tipos = (ctypes.c_char_p * len(data))()

    for i, (nombre, tipo) in enumerate(data):
        nombres[i] = ctypes.c_char_p(nombre.encode('utf-8'))
        tipos[i] = ctypes.c_char_p(tipo.encode('utf-8'))

    quicksort_pair_str_char(nombres, tipos, 0, len(data) - 1)

    # Convertir los datos ordenados de arrays de strings de C++ a Python
    
    nombres_ordenados = [nombre.decode('utf-8') for nombre in nombres]
    tipos_ordenados = [tipo.decode('utf-8') for tipo in tipos]

    # Guardar los datos ordenados en un nuevo archivo CSV
    output_file_path = "datos_ordenados.csv"
    with open(output_file_path, 'w', newline='', encoding='utf-8') as csvfile:
        
        writer = csv.writer(csvfile, delimiter=';')
        
        # Escribir el encabezado en el archivo csv
        writer.writerow(['nombre', 'tipo'])  
        for nombre, tipo in zip(nombres_ordenados, tipos_ordenados):
        
            writer.writerow([nombre, tipo])

    print(f"Datos ordenados guardados en: {output_file_path}")

# llamar a la función print_sorted_data con el archivo CSV
file_path = "listado.csv"
mensajeGuardado(file_path)
