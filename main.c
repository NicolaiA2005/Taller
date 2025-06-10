#include <stdio.h>
#include "funciones.h"

int main() {
    struct CrearLibro libros[10]; 
    int contador = 0; 
    int opc; 

    do {
        printf("\n--- Biblioteca ---\n");
        printf("1. Registrar libro\n");
        printf("2. Mostrar libros\n");
        printf("3. Buscar libro\n");
        printf("4. Actualizar estado\n");
        printf("5. Eliminar libro\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                registrarLibro(libros, &contador);
                break;
            case 2:
                mostrarLibros(libros, contador);
                break;
            case 3:
                buscarLibro(libros, contador);
                break;
            case 4:
                actualizarEstado(libros, contador);
                break;
            case 5:
                eliminarLibro(libros, &contador);
                break;
            case 6:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (opc != 6);

    return 0;
}
