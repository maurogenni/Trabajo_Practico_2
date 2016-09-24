typedef struct
{
    char nombre[31];
    int edad;
    int dni;
    int flagEstado;
}ePer;

int validarRango(int x, int inf, int sup);
void InicVector(ePer persona[], int cantPersonas);
void alta(ePer persona[], int cantPersonas);
void borrar(ePer persona[], int cantPersonas);
void mostrar(ePer persona[], int cantPersonas, int criterio);
void graficar(ePer persona[], int cantPersonas);

