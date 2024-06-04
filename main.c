#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tope 5

void menu(int *opcion){
    printf("--------------------\n");
    printf("| 1) Elegir Rubik  |\n| 3) Salir         |\n");
    printf("--------------------\n");
    scanf("%d", opcion);
}

void inicializarMatiz(int matriz[tope][tope], int cantColors){
    srand(time(NULL));      //Hace que los numeros que simulan los colores sean diferentes en cada ejecucion del programa
    for (int i=0; i<cantColors; i++){
        for (int j=0; j<cantColors; j++){
            matriz[i][j] = rand() % cantColors+1;
        }
    }
}

void elegirRubik(int *tam, int matriz[tope][tope]){
    printf("Elegi el Rubik:\n 3) 3x3\n 4) 4x4\n 5) 5x5\n");
    scanf("%d", tam);
    while (*tam < 3 || *tam > 5){
        printf("Opcion invalida. Ingrese nuevamente una opcion valida\n");
        scanf("%d", tam);
    }
    printf("--------------\n");
    printf("|Cargandoo...|\n");
    printf("--------------\n");
    inicializarMatiz(matriz,*tam);
}

void mostrarRubik(int matriz[tope][tope], int tam){
    for (int i=0; i<tam; i++){
        for (int j=0; j<tam; j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
}

void jugar(int matriz[tope][tope], int tam){
    char movimiento;
    printf("i) Izquierda\n d) Derecha\n a) Arrbia\n b) Abajo\n v) Volver al menu\n");
    scanf("%c ", &movimiento);
    while (movimiento != 'v'){
        switch (movimiento){
            case 'i':
                /* izquierda(matriz,tam); */
                mostrarRubik(matriz,tam);
                break;
            case 'd':
                /* derecha(matriz,tam); */
                mostrarRubik(matriz,tam);
                break;
            case 'a':
                /* arriba(matriz,tam); */
                mostrarRubik(matriz,tam);
                break;
            case 'b':
                /* abajo(matriz,tam); */
                mostrarRubik(matriz,tam);
                break;
            case 'v':
                break;
            default:
                printf("Movimiento no valido.\n");
                break;
        }
        printf("i) Izquierda\n d) Derecha\n a) Arrbia\n b) Abajo\n v) Volver al menu\n");
        scanf("%c ", &movimiento);
    }
}

int main()
{
    int opcion, tam;
    int matriz[tope][tope];
    do {
        menu(&opcion);
        switch (opcion) {
            case 1:
                elegirRubik(&tam,matriz);
                mostrarRubik(matriz, tam);
                jugar(matriz, tam);
                break;
            case 2:
                printf("Gracias por jugar.\n");
                break;
            default:
                printf("Opción no valida.\n");
                break;
        }
    } while (opcion != 2);
    return 0;
}
