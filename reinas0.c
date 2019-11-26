#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <omp.h>
#include <time.h>
/*
Sencilla solución de el problema de las 8 reinas usando recursividad 
(backtracking), con arrays dinámicos. (Este código solo imprime una solución)
*/


int *crearVec(int t);
void llenarPositivo(int *v,int t);
void reinas(int i,int *vec,int *puesto,int *diag2_1,int *diag1_2);
void imp(int *vec);
int reina=0;
int n;
int main(int argc, char const *argv[]){

    int *vec=NULL,*puesto=NULL,*diag2_1=NULL,*diag1_2=NULL;
    printf("Introduzca el número de reinas a colocar\n");
    scanf("%d", &n);


     #pragma omp parallel num_threads(2)
{
    vec = crearVec(n);
    puesto = crearVec(n);
    diag2_1 = crearVec((n*2)-1);
    diag1_2 = crearVec((n*2)-1);
}

    #pragma omp parallel num_threads(2)
{
    llenarPositivo(puesto,n);
    llenarPositivo(diag2_1,(n*2)-1);
    llenarPositivo(diag1_2,(n*2)-1);
}

    double start_time = omp_get_wtime();
    reinas(0,vec,puesto,diag2_1,diag1_2);
    imp(vec);

    double tiempo = omp_get_wtime() - start_time;
    printf("Tiempo de ejecución: %f segundos\n",tiempo);
    return 0;

}

int *crearVec(int t){
    int *v=NULL;
    if((v=malloc(sizeof(int)*t))==NULL){ 
        printf("Sin memoria suficiente\n");
        return NULL;
    }
    return v;

}

void llenarPositivo(int *v,int t){
    int i;
   
    #pragma omp parallel for default(none) shared(t, v) private(i) schedule(auto)
    for(i=0;i<t;i++){
        v[i] = 1;
    }

}

void reinas(int i,int *vec,int *puesto,int *diag2_1,int *diag1_2)
{
    int j;


    for(j=0;j<n;j++){
            if(puesto[j] && diag2_1[i+j] && diag1_2[i-j+(n-1)]){
                vec[i] = j;
                puesto[j] = 0;
                diag2_1[i+j] = 0;
                diag1_2[i-j+(n-1)] = 0;
                reina++;
                if(i<(n-1)){
                    reinas(i+1,vec,puesto,diag2_1,diag1_2);
                    if(reina<n){
                        puesto[j] = 1;
                        diag2_1[i+j] = 1;
                        diag1_2[i-j+(n-1)] = 1;
                        reina--;
                    }
                }
            }
    
    }
}

void imp(int *vec){
    int i,j;
    printf("###-Tablero-###\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j==vec[i]){
                printf(" Q ");
            }else{
                printf(" 0 ");
            }
        }
        printf("\n");
    }
}
