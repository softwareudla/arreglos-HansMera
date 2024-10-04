#include <stdio.h>

int main(int argc, char *argv[]) {
    // HANS MERA Y CAYETANA AILLON
    int notase[5][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int i = 0, n = 0, m = 0, imp = 0, maxm = 0, minm = 10, maxe = 0, mine = 10;
    float prom = 0, prom1 = 0;
    char estu[5][20];
    char mater[3][20] = {"Matemática", "Lenguaje", "Física"};

    printf("Para iniciar el programa digite 1, si desea terminar digite 0: ");
    scanf("%d", &n);
    
    while (n != 0 && n != 1) {
        printf("El valor ingresado no es correcto, por favor inténtelo nuevamente: ");
        scanf("%d", &n);
    }

    while (n == 1) {
        printf("Escribe 1 si quieres cambiar el nombre, Escribe 2 si quieres cambiar las notas: ");
        scanf("%d", &m);
        
        while (m != 1 && m != 2) {
            printf("El valor ingresado no es correcto, por favor inténtelo nuevamente: ");
            scanf("%d", &m);
        }

        if (m == 1) {  // Cambiar nombre del estudiante
            printf("Seleccione el número de estudiante del que desea registrar el nombre (del 1-5): ");
            scanf("%d", &i);

            while (i < 1 || i > 5) {
                printf("El valor ingresado no es correcto, por favor inténtelo nuevamente: ");
                scanf("%d", &i);
            }

            i = i - 1;  // Ajustamos índice para empezar desde 0
            printf("Por favor, ingrese el nombre del estudiante: ");
            scanf("%s", estu[i]);  // Guardamos el nombre en la posición correcta
            
        } else if (m == 2) {  // Cambiar notas del estudiante
            printf("Seleccione el número de estudiante para ingresar las notas (del 1-5): ");
            scanf("%d", &i);

            while (i < 1 || i > 5) {
                printf("El valor ingresado no es correcto, por favor inténtelo nuevamente: ");
                scanf("%d", &i);
            }

            i = i - 1;  // Ajustamos índice para empezar desde 0
            printf("Por favor, ingrese las notas de la Asignatura 1, 2 y 3 del estudiante %s: \n", estu[i]);

            for (int k = 0; k < 3; k++) {
                scanf("%d", &notase[i][k]);
                while (notase[i][k] < 0 || notase[i][k] > 10) {
                    printf("La calificación ingresada es incorrecta, debe estar entre 0 y 10: ");
                    scanf("%d", &notase[i][k]);
                }
            }
        }

        printf("Si deseas terminar el programa digita 0, sino digita 1: ");
        scanf("%d", &n);

        while (n != 0 && n != 1) {
            printf("El valor ingresado no es correcto, por favor inténtelo nuevamente: ");
            scanf("%d", &n);
        }
    }

    // Calcular y mostrar promedios por materia
    for (imp = 0; imp < 3; imp++) {
        prom1 = 0;
        for (int u = 0; u < 5; u++) {
            prom1 += notase[u][imp];
            // Sumamos las notas de todos los estudiantes en la materia
            if (notase[u][imp] > maxm) {
                maxm = notase[u][imp];
            }
            if (notase[u][imp] < minm) {
                minm = notase[u][imp];
            }
        }
        prom1 /= 5.0;  // Promedio (dividido por 5.0 para realizar una división de punto flotante)
        printf("El promedio de %s es: %.2f \n", mater[imp], prom1);  // Imprimimos el promedio con dos decimales
        printf("La nota más alta de la materia es %d, la nota más baja de la materia es %d. \n", maxm, minm);
        maxm = 0;
        minm = 10;
    }

    // Calcular y mostrar promedios por estudiante
    for (imp = 0; imp < 5; imp++) {
        printf("El estudiante %s tiene las siguientes calificaciones:\n", estu[imp]);
        prom = 0;
        maxe = 0;
        mine = 10;
        for (i = 0; i < 3; i++) {
            printf("En %s tiene %d \n", mater[i], notase[imp][i]);
            prom += notase[imp][i];  // Sumamos las notas del estudiante
            if (notase[imp][i] > maxe) {
                maxe = notase[imp][i];
            }
            if (notase[imp][i] < mine) {
                mine = notase[imp][i];
            }
        }
        prom /= 3.0;  // Promedio (dividido por 3.0 para realizar una división de punto flotante)
        printf("El promedio del estudiante es: %.2f \n", prom);  // Imprimimos el promedio con dos decimales
        printf("La nota más alta del estudiante es %d, la nota más baja del estudiante es %d. \n", maxe, mine);

        // Determinamos si el estudiante aprueba o no
        if (prom >= 6.0) {
            printf("El estudiante aprueba\n");
        } else {
            printf("El estudiante no aprueba\n");
        }
    }

    return 0;
}
