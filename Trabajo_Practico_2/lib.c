#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

/** \brief valida el rango de opciones entre los que se puede elejir.
  * \param int x que es numero a validar.
  * \param int inf que es limite inferior del rango.
  * \param int sup es el limite superior del rango.
  * \return void
  *
  */

int validarRango(int x, int inf, int sup)
 {
    int esValido=0;
    if (x>=inf && x<=sup)
    {
        esValido= 1;
    }
 return esValido;
 }



 /** \brief inicializa el vector en 0.
  * \param un dato del tipo ePer que es el vector a inicializar.
  * \param int cantPersonas que es la cantidad de personas en el array.
  * \return void
  *
  */

void InicVector(ePer persona[], int cantPersonas)
{
    int i;
    for(i=0;i<cantPersonas;i++)
    {
        persona[i].flagEstado=0;
        persona[i].dni=0;
        persona[i].edad=0;
    }
}



 /** \brief da de alta una persona.
  * \param un dato del tipo ePer que es donde se va a guardar la persona.
  * \param int cantPersonas que es la cantidad de personas en el array.
  * \return void
  *
  */


     void alta(ePer persona[], int cantPersonas)
 {
     int flagPer=0,i,j;
     ePer auxPersona;
     for (i=0;i<cantPersonas;i++)
     {
         if(persona[i].flagEstado==0)
         {
             fflush(stdin);
             printf("Ingresar Nombre: ");
             gets(auxPersona.nombre);

             printf("Ingresar Edad: ");
             scanf("%d", &auxPersona.edad);
             while((auxPersona.edad<1) || (auxPersona.edad>150))
             {
                 printf("ERROR !!! Edad incorrecta. Reingese: ");
                 scanf("%d", &auxPersona.edad);
             }
             printf("Ingrese DNI: ");
             scanf("%d", &auxPersona.dni);
             while((auxPersona.dni<1000000) || (auxPersona.dni>99999999))
             {
                 printf("ERROR !!! DNI inexistente. Reingrese: ");
                 scanf("%d", &auxPersona.dni);
             }
             for(j=0;j<cantPersonas;j++)
             {
                 if(persona[j].dni==auxPersona.dni)
                 {
                     printf("\nEste DNI ya fue ingresado.\n\n");
                     system("pause");
                     break;
                 }
                 else
                 {
                     flagPer=1;
                     auxPersona.flagEstado=1;
                     persona[i]=auxPersona;
                     printf("\nIngresado correctamente.\n\n");
                     system("pause");
                     break;
                 }
             }
             break;
         }
     }
     if(i==cantPersonas && flagPer==0)
     {
         printf("\nNo hay espacio para mas personas:");
         system("pause");
     }

 }





     /** \brief elimina a una persona del vector.
  * \param el DNI de la persona que se desea borrar.
  * \param int cantPersonas que es la cantidad de personas en el array.
  * \return void
  *
  */

void borrar(ePer persona[], int cantPersonas)
{
    int i, auxDni, flagPersona;
    printf("\nIngrese el DNI de la persona a borrar: ");
    scanf("%d", &auxDni);
    for(i=0;i<cantPersonas;i++)
    {
        if((persona[i].dni==auxDni) && (persona[i].flagEstado==1))
        {
            persona[i].flagEstado=0;
            persona[i].dni=0;
            flagPersona=1;
            printf("\nLa persona fue eliminada con exito.");
            system("\npause");
            break;
             if((flagPersona==0) && (i==cantPersonas))
             {
                 printf("\nEste DNI no fue ingresado anteriormente.");
                 system("pause");
             }
        }


    fflush(stdin);
    }
}




 /** \brief muestra las personas cargadas en el array.
  * \param el array cargado con las personas.
  * \param int cantPersonas que es la cantidad de personas en el array.
  * \param int criterio es por lo que se va a ordenar. Si el criterio es 1 se ordena de la A a la Z, y si el criterio es 0 se ordena de la Z a la A
  * \return void
  *
  */

void mostrar(ePer persona[], int cantPersonas, int criterio)
{
    fflush(stdin);
    int i, j;
    ePer auxPersona;
    system("cls");
    printf("Personas listadas por nombre: \n\n");

    if(criterio==1)
    {
    for(i=0;i<cantPersonas-1;i++)
    {
        for(j=i+1;j<cantPersonas;j++)
        {
            if(strcmp(persona[i].nombre, persona[j].nombre) >0 && criterio==1)
            {
                auxPersona=persona[i];
                persona[i]=persona[j];
                persona[j]=auxPersona;
            }
            else if(strcmp(persona[i].nombre, persona[j].nombre) < 0 && criterio ==0)
            {
                auxPersona=persona[i];
                persona[i]=persona[j];
                persona[j]=auxPersona;
            }
        }
    }
    }
    for(i=0;i<20;i++)
    {
        if(persona[i].flagEstado==1)
        {
        printf("Nombre: %s   Edad: %d   DNI: %d\n", persona[i].nombre, persona[i].edad, persona[i].dni);
        }
    }
    system("pause");
    system("cls");
    fflush(stdin);
}



   /** \brief grafica las personas del vector.
  * \param el array donde se encuentran cargadas las personas.
  * \param int cantPersonas que es la cantidad de personas en el array.
  * \return void
  *
  */


void graficar(ePer persona[], int cantPersonas)
{
    fflush(stdin);
    int i, max, menor=0, entre=0, mayor=0;
    for(i=0;i<cantPersonas;i++)
    {
        if(persona[i].flagEstado!=0)
        {
            if(persona[i].edad<=18)
            {
                menor++;
            }
            else
            {
                if((persona[i].edad>18) && (persona[i].edad<35))
                {
                    entre++;
                }
                else
                {
                    mayor++;
                }
            }
        }
    }

    if((menor>=entre) && (menor>=mayor))
    {
        max=menor;
    }
    else
    {
        if((entre>=menor) && (entre>=mayor))
        {
            max=entre;
        }
        if((mayor>=menor) && (mayor>=entre));
        {
            max=mayor;
        }
    }

    for(i=max;i>0;i--)
    {
        if((i==menor) && (i==entre) && (i==mayor))
        {
            printf(" *\t  *\t  *\n");
            menor--;
            entre--;
            mayor--;
        }
        if((i==menor) && (i==entre))
        {
            printf(" *\t  *\t  \n");
            menor--;
            entre--;
        }
        if((i==menor) && (i==mayor))
        {
            printf(" *\t  \t  *\n");
            menor--;
            mayor--;
        }
        if((i==entre) && (i==mayor))
        {
            printf("  \t  *\t  *\n");
            entre--;
            mayor--;
        }
        if(i==menor)
        {
            printf(" *\t  \t  \n");
            menor--;
        }
        if(i==entre)
        {
            printf(" \t  *\t  \n");
            entre--;
        }
        if(i==mayor)
        {
            printf(" \t  \t  *\n");
            mayor--;
        }
    }
    printf("<18\t19-35\t>35\n");
    system("pause");
    system("cls");
}
