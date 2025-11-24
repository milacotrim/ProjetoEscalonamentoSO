#include <stdio.h>


int main() {


    int n, i, j;


    printf("Quantidade de processos: ");
    scanf("%d", &n);


    int burst[n], waiting[n], turnaround[n], p[n];


   
    printf("\nTempo de burst de cada processo:\n");
    for (i = 0; i < n; i++) {
        p[i] = i + 1;  
        printf("P%d: ", i + 1);
        scanf("%d", &burst[i]);
    }


   
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (burst[j] < burst[i]) {


             
                int temp = burst[i];
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


   
    printf("\n--- SJF (NÃO PREEMPTIVO) ---\n");
    printf("Proc\tBurst\tEspera\tTurnaround\n");


    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n",
               p[i], burst[i], waiting[i], turnaround[i]);
    }


    return 0;
}











