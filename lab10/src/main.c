#include <stdio.h>

/*
  Лабораторна робота №10
  Завдання №5
  Тема: Масиви та обчислення значень
  Автор: Дінара Баршак
  Дата: 2025
*/

int main() {
    int n;
    printf("Введіть кількість елементів масиву: ");
    scanf("%d", &n);

    float arr[n];
    float sum = 0;

    printf("Введіть елементи масиву:\n");

    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%f", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            sum += arr[i];
        }
    }

    printf("Сума додатних елементів = %.3f\n", sum);

    return 0;
}
