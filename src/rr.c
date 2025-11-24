#include <stdio.h>

typedef struct {
    int pid;
    int burst;
    int remaining;
    int arrival;
    int waiting;
    int turnaround;
} Process;

int main() {
    int n, quantum;
    
    printf("Digite o número de processos: ");
    scanf("%d", &n);
    
    Process p[n];
    
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Digite o tempo de chegada do processo P%d: ", p[i].pid);
        scanf("%d", &p[i].arrival);
        printf("Digite o burst time do processo P%d: ", p[i].pid);
        scanf("%d", &p[i].burst);
        p[i].remaining = p[i].burst;
        p[i].waiting = 0;
        p[i].turnaround = 0;
    }
    
    printf("Digite o quantum: ");
    scanf("%d", &quantum);
    
    int time = 0, done;
    
    printf("\nOrdem de execução:\n");
    do {
        done = 1;
        for (int i = 0; i < n; i++) {
            if (p[i].remaining > 0) {
                done = 0;
                if (p[i].remaining > quantum) {
                    printf("P%d -> ", p[i].pid);
                    time += quantum;
                    p[i].remaining -= quantum;
                } else {
                    printf("P%d -> ", p[i].pid);
                    time += p[i].remaining;
                    p[i].waiting = time - p[i].burst - p[i].arrival;
                    p[i].turnaround = p[i].waiting + p[i].burst;
                    p[i].remaining = 0;
                }
            }
        }
    } while (!done);
    
    printf("Fim\n\n");
    
    printf("PID\tChegada\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival, p[i].burst, p[i].waiting, p[i].turnaround);
    }
    
    return 0;
}
