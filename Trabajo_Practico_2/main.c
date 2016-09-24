#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int main()
{
    int opcion;
    ePer persona[20];
    InicVector(persona, 20);

    while(opcion!=5)
    {
        system("cls");
        printf("MENU DE OPCIONES: \n\n");
        printf("1- Agregar una persona.\n");
        printf("2- Borrar una persona.\n");
        printf("3- Imprimir lista de personas.\n");
        printf("4- Mostrar grafico de edades.\n");
        printf("5- Salir.\n\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        while(!validarRango(opcion,1,5))
        {
            printf("\nERROR !!! Ingrese opcion entre 1 y 5: ");
            scanf("%d", &opcion);
        }

        switch(opcion)
        {
        case 1:alta(persona, 20);
                fflush(stdin);
            break;
        case 2:borrar(persona, 20);
                fflush(stdin);
            break;
        case 3:mostrar(persona, 20, 1);
                fflush(stdin);
            break;
        case 4:graficar(persona, 20);
                fflush(stdin);
            break;
        case 5:
            break;
        }
    }

    return 0;
}
