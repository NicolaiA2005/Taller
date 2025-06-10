struct CrearLibro
{
    int id; 
    char titulo[100]; 
    char autor[50]; 
    int año; 
    char estado[15];
};
void registrarLibro(struct CrearLibro libros[], int *contador);
void mostrarLibros(const struct CrearLibro libros[], int contador);
void buscarLibro(const struct CrearLibro libros[], int contador);
void actualizarEstado(struct CrearLibro libros[], int contador);
void eliminarLibro(struct CrearLibro libros[], int *contador);
