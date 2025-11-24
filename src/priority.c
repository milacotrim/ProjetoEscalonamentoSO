#include <stdio.h>


int main() {


    int n, i, j;


    printf("Quantidade de processos: ");
    scanf("%d", &n);


    int burst[n], priority[n], waiting[n], turnaround[n], p[n];




    printf("\nTempo de burst e prioridade de cada processo:\n");
    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("\nP%d\n", i + 1);
        printf("Burst: ");
        scanf("%d", &burst[i]);
        printf("Prioridade (menor valor = maior prioridade): ");
        scanf("%d", &priority[i]);
    }


   
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (priority[j] < priority[i]) {
                int temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;


             
                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;


               
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }


   
    waiting[0] = 0;
    for (i = 1; i < n; i++) {
        waiting[i] = waiting[i - 1] + burst[i - 1];
    }


   
    for (i = 0; i < n; i++) {
        turnaround[i] = waiting[i] + burst[i];
    }


   
    printf("\n--- PRIORIDADE (NÃO-PREEMPTIVO) ---\n");
    printf("Proc\tPrior\tBurst\tEspera\tTurnaround\n");


    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               p[i], priority[i], burst[i], waiting[i], turnaround[i]);
    }


    return 0;
}

