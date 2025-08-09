#include <stdio.h>
struct process {
    int pid;
    int arrival;
    int burst;
    int remaining; //remaining burst time
    int waiting;
    int turnaround;
    int completed; // completion flag
};

int main(){
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d",&quantum);
    struct process p[n];
    for(int i=0; i<n; i++){
        p[i].pid = i+1;
        printf("Enter arrival time and burst time for the process P%d : ",i+1);
        scanf("%d %d", &p[i].arrival, &p[i].burst);

    }

    round_robin(p, n, quantum);
    float average_waiting_time = 0, average_turnaround_time =0;
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", 
               p[i].pid,
               p[i].arrival,
               p[i].burst, 
               p[i].waiting, 
               p[i].turnaround);
        
        average_waiting_time += p[i].waiting;
        average_turnaround_time += p[i].turnaround;
    }
    average_waiting_time/=n;
    average_turnaround_time /= n;
    printf("Average waiting time: %.2f\n",average_waiting_time);
    printf("average turnaround time: %.2f\n",average_turnaround_time);
    return 0;
    


}