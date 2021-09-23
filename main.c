#include<stdio.h>

#include <math.h>

void Trans(unsigned a) {
    if (a) {
        Trans(a >> 1);
        printf("%d", (a & 1));
    }
}
int main() {
    long num;
    scanf("%li", & num);
    if (num > pow(2, (8 * sizeof(unsigned int))) - 1) { //максимальное число которое может принять функция
        printf("Слишком большое число");
        return 1;
    }
    if (num == 0) {
        printf("0");
    }
    if (num)
        if (num < 0) {
            num *= -1;
            printf("-");
        }
    Trans(num);
    return 0;
}