#include<stdio.h>

void Trans(unsigned a) {
    if (a) {
        Trans(a >> 1);
        printf("%d", (a & 1));
    }
}
int main() {
    unsigned num;
    scanf("%d", & num);
    Trans(num);
    return 0;
}