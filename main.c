#include<stdio.h>

void Trans(unsigned a) {
    if (a) {
        Trans(a >> 1);
        printf("%d", (a & 1));
    }
}
int main() {
    long num;
    scanf("%li", & num);
    if (num < 0) {
        num *= -1;
        printf("-");
    }
    Trans(num);
    return 0;
}