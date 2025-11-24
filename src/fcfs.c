#include <stdio.h>


int main() {


    int n, i;


    printf("Quantidade de processos: ");
    scanf("%d", &n);


    int burst[n];
    int waiting[n];
    int turnaround[n];


    printf("\nTempo de burst de cada processo:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &burst[i]);
    }


    waiting[0] = 0;
    for (i = 1; i < n; i++) {
        waiting[i] = waiting[i - 1] + burst[i - 1];
    }


    for (i = 0; i < n; i++) {
        turnaround[i] = waiting[i] + burst[i];
    }


    printf("\n--- FCFS ---\n");
    printf("Processo\tBurst\tEspera\tTurnaround\n");




    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t%d\t%d\n",
               i + 1, burst[i], waiting[i], turnaround[i]);
    }




    return 0;
}

