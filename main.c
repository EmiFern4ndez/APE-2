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

void izquierda(int matriz[tope][tope], int tam, int fila){
    int aux;
    aux = matriz[fila][0];      // Guarda el último  (en realidad es el primer elemnto) antes de que se sobrescriba
    for (int i=0; i<tam-1; i++){
        matriz[fila][i] = matriz[fila][i+1];    // Mueve cada elemento un lugar hacia la izquierda
    }
    matriz[fila][tam-1] = aux;
}

void derecha(int matriz[tope][tope], int tam, int fila){
    int aux;
    aux = matriz[fila][tam - 1];    // Guarda el último elemento antes de que se sobrescriba
    for (int j=tam-1; j>0; j--) {
        matriz[fila][j] = matriz[fila][j-1];    // Mueve cada elemento un lugar hacia la derecha
    }
    matriz[fila][0] = aux;  // Asigna el último elemento al primer lugar
}

void arriba(int matriz[tope][tope], int tam, int colum){
    int aux;
    aux = matriz[0][colum];     // Guarda el último elemento antes de que se sobrescriba
    for (int i=0; i<tam-1; i++){
        matriz[i][colum] = matriz[i+1][colum];  // Mueve cada elemento un lugar hacia arriba
    }
    matriz[tam-1][colum] = aux;
}

void abajo(int matriz[tope][tope], int tam, int colum){
    int aux;
    aux = matriz[tam-1][colum];     // Guarda el último  (en realidad es el primer elemnto) antes de que se sobrescriba
    for (int i=tam-1; i>0; i--){
        matriz[i][colum] = matriz[i+1][colum];  // Mueve cada elemento un lugar hacia abajo
    }
    matriz[0][colum] = aux;
}

void jugar(int matriz[tope][tope], int tam){
    char movimiento;
    int fila, columna;
    printf(" i) Izquierda\n d) Derecha\n a) Arriba\n b) Abajo\n v) Volver al menú\n");
    while (1) {     //Esto crea un bucle hasta encontrar un break
        printf("Elige un movimiento: ");
        scanf(" %c", &movimiento);
        if (movimiento == 'v') {
            break;
        }
        switch (movimiento) {
            case 'i':
                printf("Ingrese la fila:\n");
                scanf("%d", &fila);
                if (fila < 1 || fila > tam){
                    printf("Fila invalida, ingrese otra.\n");
                    scanf("%d", &fila);
                }
                izquierda(matriz,tam,fila-1);
                mostrarRubik(matriz,tam);
                break;
            case 'd':
                printf("Ingrese la fila:\n");
                scanf("%d", &fila);
                if (fila < 1 || fila > tam){
                    printf("Fila invalida, ingrese otra.\n");
                    scanf("%d", &fila);
                }
                derecha(matriz, tam,fila-1);
                mostrarRubik(matriz,tam);
                break;
            case 'a':
                printf("Ingrese la columna:\n");
                scanf("%d", &columna);
                if (fila < 1 || columna > tam){
                    printf("columna invalida, ingrese otra.\n");
                    scanf("%d", &columna);
                }
                arriba(matriz,tam,columna);
                mostrarRubik(matriz, tam);
                break;
            case 'b':
                printf("Ingrese la columna:\n");
                scanf("%d", &columna);
                if (fila < 1 || columna > tam){
                    printf("columna invalida, ingrese otra.\n");
                    scanf("%d", &columna);
                }
                abajo(matriz,tam,columna);
                mostrarRubik(matriz,tam);
                break;
            default:
                printf("Movimiento no válido.\n");
                break;
        }
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
