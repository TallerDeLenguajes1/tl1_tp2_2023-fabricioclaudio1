#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 7
//35 elementos
int main(void){
    srand(time(NULL));
    int i,j;
    float mt[N][M], *pmt;  //problema con el numero 5 y 7 en el codigo del for anidado
    pmt=&mt[0][0];

    for (i = 0; i <= (N*M); i++) //En este for me da 36 numeros en ves de 35 por qué?
    {
        if ((i%5)==0 && i!=0){
            printf("\n");
        }
        if (i<10){
            printf(" |0%d| ",i);
        }else{
           printf(" |%d| ",i); 
        }
        (*pmt)=1+(rand()% 99);
        if ((*pmt) < 10 ){
            printf("0%.1f ", *pmt);
        }else{
            printf("%.1f ", *pmt);
        }  
        *(pmt++);
    }
  

//For anidado
/*
    for(i = 0;i<N; i++)
    {
        for(j = 0;j<M; j++)
        {
            (*pmt)=1+(rand()% 99);
            if ((*pmt) < 10 ){
                printf("0%.1f ", *pmt);
            }else{
                printf("%.1f ", *pmt);
            }
            printf(" |%d| ",j);
            *(pmt++);

        }
        *(pmt++);
        printf("||%d||\n",i);
    }
*/
    printf("\nHola\n");

    return 0;
}


