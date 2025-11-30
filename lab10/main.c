#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;

    printf("Введіть кількість рядків (N): ");
    scanf("%d", &N);

    printf("Введіть кількість стовпців (M): ");
    scanf("%d", &M);

    // Виділення пам’яті під матрицю
    int **a = malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        a[i] = malloc(M * sizeof(int));
    }

    // Введення елементів матриці
    printf("Введіть елементи матриці:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Масиви мінімальних і максимальних значень
    int *mins = malloc(N * sizeof(int));
    int *maxs = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        int mn = a[i][0];
        int mx = a[i][0];
        for (int j = 1; j < M; j++) {
            if (a[i][j] < mn) mn = a[i][j];
            if (a[i][j] > mx) mx = a[i][j];
        }
        mins[i] = mn;
        maxs[i] = mx;
    }

    // Вивід результатів
    printf("Мінімальні елементи по рядках:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", mins[i]);
    }

    printf("\nМаксимальні елементи по рядках:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", maxs[i]);
    }
    printf("\n");

    // Звільнення пам’яті
    for (int i = 0; i < N; i++) {
        free(a[i]);
    }
    free(a);
    free(mins);
    free(maxs);

    return 0;
}
