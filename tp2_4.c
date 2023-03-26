#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct{
    int velocidad;//entre 1 y 3 GHz
    int anio;//entre 2015 y 2023
    int cantidad;//entre 1 y 8
    char *tipo_cpu; //valores del arreglo tipos
}typedef compu;

void cargar(compu *pc);
void mostrar(compu *pc);
int Antigua(compu *pc);
void mostrarAntigua(compu *pc, int antigua);
int Velocidad(compu *pc);
void mostrarVelocidad(compu *pc, int veloz);

int main(){
    srand(time(NULL));
    compu pc[5];
    int n=5;

    cargar(pc);
    printf("\n");
    mostrar(pc);

    int antigua;
    antigua=Antigua(pc);
    mostrarAntigua(pc, antigua);

    int veloz;
    veloz= Velocidad(pc);
    mostrarVelocidad(pc, veloz);

    return 0;
}

void cargar(compu *pc){
    int tipoAleatorio;
    char tipos[6][10]={"Intel     ","AMD       ","Celero    ","Athlon    " ,"Core      ","Pentium   "};
    for (int i=0 ; i<5 ; i++)
    {
        
        pc->velocidad= 1 + rand()% 3;
        pc->anio= 2015 + rand()% 9;

        tipoAleatorio=rand()%6;
        pc->tipo_cpu=malloc(10*(sizeof(char)));
        for(int j=0; j<10 ; j++)
        {
            pc->tipo_cpu[j]=tipos[tipoAleatorio][j];
        }
        
        pc->cantidad=1+rand()%8;
        printf("|carga %d| ", i);
        *(pc++);
    }
    
}

void mostrar(compu *pc){
    for (int i=0 ; i<5 ; i++)
    {
        printf("|Velocidad: %d| ",pc->velocidad);

        printf("|Anio: %d| ",pc->anio);

        printf("|");
        for (int j = 0; j < 10; j++)
        {
            printf("%c",pc->tipo_cpu[j]);
        }
        printf("|");

        printf("|Cantidad: %d| ",pc->cantidad);

        *(pc++);

        printf("\n");
    }
}

int Antigua(compu *pc){
    int antigua=2023;
    for (int i=0 ; i<5 ; i++){
        if (pc->anio<antigua)
        {
            antigua=pc->anio;
        }
        *(pc++);
    }
    return antigua;

}

void mostrarAntigua(compu *pc, int antigua){
    printf("\n----Computadoras mas antiguas----\n");
    for (int i=0 ; i<5 ; i++){
        if (pc->anio==antigua)
        {
            printf("|Velocidad: %d| ",pc->velocidad);

            printf("|Anio: %d| ",pc->anio);

            printf("|");
            for (int j = 0; j < 10; j++)
                {
                    printf("%c",pc->tipo_cpu[j]);
                }
            printf("|");

            printf("|Cantidad: %d| ",pc->cantidad);

            printf("\n");
        }
        *(pc++);
    }

}

int Velocidad(compu *pc){
    int veloz=0;
    for (int i=0 ; i<5 ; i++){
        if (pc->velocidad>veloz)
        {
            veloz=pc->velocidad;
        }
        *(pc++);
    }
    return veloz;
}

void mostrarVelocidad(compu *pc, int veloz){
    printf("\n----Computadoras mas veloces----\n");
    for (int i=0 ; i<5 ; i++){
        if (pc->velocidad==veloz)
        {
            printf("|Velocidad: %d| ",pc->velocidad);

            printf("|Anio: %d| ",pc->anio);

            printf("|");
            for (int j = 0; j < 10; j++)
                {
                    printf("%c",pc->tipo_cpu[j]);
                }
            printf("|");

            printf("|Cantidad: %d| ",pc->cantidad);

            printf("\n");
        }
        *(pc++);
    }
}

