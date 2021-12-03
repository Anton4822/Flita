#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void) {
    FILE * graph;
    unsigned x = 0;
    bool check = true;
    printf("Введите колличество вершин\n");
    scanf("%d",& x);
    unsigned count = 0;
    unsigned a = 1;
    unsigned *line1 = (unsigned *)malloc(x*sizeof(unsigned));

    printf(" |");

    while (count < x) { 
        line1[count] = a;
        printf("%d ", a);
        ++a;
        ++count;
    }
    unsigned num = 1;
    unsigned countx = 0;
    unsigned **mass = (unsigned **)malloc(x*sizeof(unsigned));
    unsigned **result = (unsigned **)malloc(x*sizeof(unsigned));
    for(unsigned i = 0; i <= x;++i){
        mass[i] = (unsigned *)malloc(x*sizeof(unsigned));
        result[i]=(unsigned*)malloc(x*sizeof(unsigned));
    }
    
    printf("\n");
    for (count = 0; count < x; count++) { //запись строк в массив
        printf("%d|", num);
        num++;
        for (countx = 0; countx < x; countx++) {
            scanf("%d", & mass[count][countx]);
        }
    }


    graph = fopen("graph.dot", "w");
    fprintf(graph, "graph G{\n");
    for (unsigned i = 0; i < x; ++i)
    {
        for (unsigned g = i; g < x; ++g)
        {
            if (mass[i][g] == 0)
            {
                fprintf(graph, "%d;\n\t", (i+1));
            }
            for (int k = 0; k < mass[i][g]; ++k)
            {
                fprintf(graph, "%d -- %d;\n\t", (i+1), (g+1));
            }
        }
    }
    fprintf(graph, "}");
    fclose(graph);
    system("dot -Tpng graph.dot -o graph.png");

    unsigned z =1;
    for (unsigned i = 0; i<x; i++) {
        for (unsigned l = 0; l<x; l++) {
            result[i][l] = 0;
            for (unsigned j = 0; j<x; j++) {
                result[i][l] += mass[i][j] * mass[j][l];
            }
        }
    }

while (z<=x-1)
{
    for (unsigned i = 0; i<x; i++) {
        for (unsigned l = 0; l<x; l++) {
            for (unsigned j = 0; j<x; j++) {
                result[i][l] += mass[i][j] * result[j][l];
            }
        }
    }
    ++z;

}
 
    for (unsigned i = 0; i < x; i++)
    {
        for (unsigned j = 0; j < x; j++)
        {
            if(result[i][j]==0){
                check = false;
            }
        }
    }


    unsigned sum = 0;
    
for (count = 0; count < x; count++) {
        for (countx = 0; countx < x; countx++) {
            sum+=mass[count][countx];}

            if (sum % 2 != 0) {
                printf("Не эйлеров цикл");
                return 0;
            }
            sum = 0;
        
}
printf("Эйлеров цикл\n");


    return 0;
}