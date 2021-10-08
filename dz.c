#include <stdio.h>

#include <stdbool.h>

#include <malloc.h>

int main() {
    FILE * graph;
    int x, y;
    printf("Введите размер матрицы\n");
    scanf("%dx%d", & y, & x);
    int count = 0;
    char a = 'A';
    char line1[x];

    printf(" |");

    while (count <= (x - 1)) { //вывод первой строки
        line1[count] = a;
        printf("%c ", a);
        a++;
        count++;
    }
    count = 0;
    int num = 1;
    int countx;
    //int **mass=malloc(x*y*sizeof(int));

    int mass[y][x];
    printf("\n");
    for (count; count <= (y - 1); count++) { //запись строк в массив
        printf("%d|", num);
        num++;
        countx = 0;
        for (countx; countx <= (x - 1); countx++) {
            scanf("%d", & mass[count][countx]);
        }
    }
    count, countx = 0;
    bool ch = false;
    //проверка
    for (count = 0; count <= y - 1; count++) {
        ch = false;
        for (countx = 0; countx <= x - 1; countx++) {
            if (mass[count][countx] != 0) {
                ch = true;
            }
        }
        if (ch == false) {
            printf("\nграф не связнНый\n");
        }

    }
    if (ch == true) {
        printf("\nграф связанный\n");
    }
    /* int spflag, flag = 0;
    countx = 0;
    int county = 0;
    while (countx != x - 1) {
        if (mass[0][countx] == 1 && mass[1][countx] == 1) {
            spflag = countx;
        }
        countx++;
    }
    countx = 0;
    county = 1;
  //  while (county != (y - 1)) {
        while (countx != (x - 1)) {

            if (mass[county][countx] == 1 && mass[county + 1][countx] == 1) {
                county++;
                countx = 0;
            }
            if (countx == (x - 1) && !mass[county][countx] == 1 && mass[county + 1][countx] == 1 && county != (x - 1)) {
                printf("Граф не связанный");

            }
            if (county == (y - 1)) {
                countx = 0;
                while (countx != (x - 1)) {
                    if (mass[county][countx] == 1 && mass[0][countx] == 1 && countx != spflag) {
                        printf("Граф связанный");
                        break;
                    }
                    countx++;
                }
            }
        }
    }
*/ //---------------------------запись в фаил-------------------------------//

    count, countx = 0;
    a = 'A';
    int cnt[] = {
        0,
        0
    };
    int z = 0;
    graph = fopen("graph.dot", "w");
    fprintf(graph, "graph G{\n");
    for (countx; countx <= (x - 1); countx++) {
        for (count = 0; count <= (y - 1); count++) {
            if (mass[count][countx] == 1) {
                cnt[z] = count + 1;
                z++;

            }
        }

        if (z == 2) {
            fprintf(graph, "%d -- %d[label = \"%c\"]\n", cnt[0], cnt[1], (a + countx));
            z = 0;
        }

    }
    fprintf(graph, "}");
    fclose(graph);

    return 0;
}