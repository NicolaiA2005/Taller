#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "funciones.h"

void registrarLibro(struct CrearLibro libros[], int *contador) {
    if (*contador >= 10) { // Restricción de máximo 10 libros
        printf("No se pueden registrar más libros.\n");
        return;
    }

    struct CrearLibro nuevoLibro;
    printf("Ingrese el ID del libro: ");
    scanf("%d", &nuevoLibro.id);

    // Validar ID único
    for (int i = 0; i < *contador; i++) {
        if (libros[i].id == nuevoLibro.id) {
            printf("El ID ya existe. Intente nuevamente.\n");
            return;
        }
    }

    printf("Ingrese el título del libro: ");
    getchar(); // Limpiar buffer
    fgets(nuevoLibro.titulo, 100, stdin);
    nuevoLibro.titulo[strcspn(nuevoLibro.titulo, "\n")] = '\0'; // Eliminar salto de línea

    printf("Ingrese el autor del libro: ");
    fgets(nuevoLibro.autor, 50, stdin);
    nuevoLibro.autor[strcspn(nuevoLibro.autor, "\n")] = '\0';

    printf("Ingrese el año de publicación: ");
    scanf("%d", &nuevoLibro.año);

    strcpy(nuevoLibro.estado, "Disponible");

    libros[*contador] = nuevoLibro;
    (*contador)++;
    printf("Libro registrado exitosamente.\n");
}

void mostrarLibros(const struct CrearLibro libros[], int contador) {
    printf("ID\tTítulo\t\tAutor\t\tAño\tEstado\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < contador; i++) {
        printf("%d\t%s\t%s\t%d\t%s\n", libros[i].id, libros[i].titulo, libros[i].autor, libros[i].año, libros[i].estado);
    }
}

void buscarLibro(const struct CrearLibro libros[], int contador) {
    char criterio[100];
    printf("Ingrese el título o ID del libro a buscar: ");
    getchar(); // Limpiar buffer
    fgets(criterio, 100, stdin);
    criterio[strcspn(criterio, "\n")] = '\0';

    for (int i = 0; i < contador; i++) {
        if (strcmp(libros[i].titulo, criterio) == 0 || atoi(criterio) == libros[i].id) {
            printf("ID: %d\nTítulo: %s\nAutor: %s\nAño: %d\nEstado: %s\n", libros[i].id, libros[i].titulo, libros[i].autor, libros[i].año, libros[i].estado);
            return;
        }
    }
    printf("Libro no encontrado.\n");
}

void actualizarEstado(struct CrearLibro libros[], int contador) {
    int id;
    printf("Ingrese el ID del libro para actualizar el estado: ");
    scanf("%d", &id);

    for (int i = 0; i < contador; i++) {
        if (libros[i].id == id) {
            if (strcmp(libros[i].estado, "Disponible") == 0) {
                strcpy(libros[i].estado, "Prestado");
            } else {
                strcpy(libros[i].estado, "Disponible");
            }
            printf("Estado actualizado exitosamente.\n");
            return;
        }
    }
    printf("Libro no encontrado.\n");
}

void eliminarLibro(struct CrearLibro libros[], int *contador) {
    int id;
    printf("Ingrese el ID del libro a eliminar: ");
    scanf("%d", &id);

    for (int i = 0; i < *contador; i++) {
        if (libros[i].id == id) {
            for (int j = i; j < *contador - 1; j++) {
                libros[j] = libros[j + 1];
            }
            (*contador)--;
            printf("Libro eliminado exitosamente.\n");
            return;
        }
    }
    printf("Libro no encontrado.\n");
}
