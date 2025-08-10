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

void round_robin(struct process p[], int n, int quantum){
    int time =0;
    int completed=0;
    for(int i=0; i<n; i++){
        p[i].remaining = p[i].burst;
        p[i].completed =0; //completion flag
        p[i].waiting=0;
        p[i].turnaround=0;

    }
    while(completed!=n){
        int executed=0; // flag to check if any process was executed in this iteration
        for(int i=0; i<n; i++){
            if(!p[i].completed && p[i].arrival <= time){
                executed =1;
                if(p[i].remaining > quantum){
                    time += quantum;
                    p[i].remaining -=quantum;
                }
                else{
                    time += p[i].remaining;
                    p[i].remaining =0;
                    p[i].completed =1;
                    completed++;
                    p[i].turnaround = time - p[i].arrival;
                    p[i].waiting = p[i].turnaround - p[i].burst;
                }
            }
            if(!executed){
                time++; //increment time if no process was executed
            }
        }

    }
}

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
    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnarounds\n");

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