#include <stdio.h>
int main() {
    int n;
    printf("Введіть кількість чисел: ");
    scanf("%d", &n);
    if (n < 2 || n > 20) {
        printf("Кількість чисел повинна бути в діапазоні від 2 до 20.\n");
        return 1;
    }
    int numbers[n];
    printf("Введіть числа, розділені пробілом: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    int result = lcm_multiple(numbers, n);
    printf("Найменше спільне кратне: %d\n", result);
    return 0;
}
// НСД (Евклід)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
// НСК (2)
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// НСК (2<)
int lcm_multiple(int numbers[], int n) {
    int result = numbers[0];
    for (int i = 1; i < n; i++) {
        result = lcm(result, numbers[i]);
    }
    return result;
    }