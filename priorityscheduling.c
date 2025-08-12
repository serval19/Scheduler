#include <stdio.h>
struct process {
    int pid;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};
void sortprocess(struct process p[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(p[j].priority > p[j+1].priority){
                struct process temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}
void findtimes(struct process p[], int n){
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    p[0].waiting_time = 0;
    for(int i=1; i<n; i++){
        p[i].waiting_time = p[i-1].waiting_time + p[i-1].burst_time;

    }
    for(int i=0; i<n; i++){
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;

    }
    printf("process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", 
               p[i].pid, 
               p[i].burst_time, 
               p[i].priority, 
               p[i].waiting_time, 
               p[i].turnaround_time);
    }

}
int main(){
    int n;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    struct process p[n];
    for(int i=0; i<n; i++){
        p[i].pid = i+1;
        printf("Enter burst time and priority for process P%d: ", i+1);
        scanf("%d %d", &p[i].burst_time, &p[i].priority);

    }
    sortprocess(p, n);
    findtimes(p, n);
    return 0;
}