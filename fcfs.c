#include <stdio.h>
// new datatype for representing a process
struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
};
 
void sortbyarrivaltime(struct process p[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(p[i].arrival_time > p[j+1].arrival_time){
                struct process temp= p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}

void findtimes(struct process p[], int n){
    p[0].completion_time=p[0].arrival_time + p[0].burst_time;
    p[0].turnaround_time = p[0].completion_time - p[0].arrival_time;
    p[0].waiting_time = p[0].turnaround_time - p[0].burst_time;
    for(int i=1; i<n; i++){
        int start_time=(p[i-1].completion_time > p[i].arrival_time) ? p[i-1].completion_time : p[i].arrival_time;
        p[i].completion_time = start_time + p[i].burst_time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;

    }
}

void printresults(struct process p[], int n){
    float average_waiting_time =0;
    float average_turnaround_time =0;
    printf("P_ID\tArrival_Time\tBurst_Time\tCompletion_Time\tWaiting_Time\tTurnaround_Time\n");
    printf("-----------------------------------------------------------------------------------\n");
    for( int i=0;i<n;i++){
        average_waiting_time+= p[i].waiting_time;
        average_turnaround_time+= p[i].turnaround_time;
         printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               p[i].pid,
               p[i].arrival_time,
               p[i].burst_time,
               p[i].completion_time,
               p[i].waiting_time,
               p[i].turnaround_time);

    }
    average_waiting_time /=n;
    average_turnaround_time /=n;
     printf("\nAverage Waiting Time: %.2f\n", average_waiting_time);
    printf("Average Turnaround Time: %.2f\n", average_turnaround_time);

}
int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    struct process processes[n];
    for(int i=0;i<n;i++){
        processes[i].pid = i+1;
        printf("Enter arrival time and burst time for process P%d: ",i+1);
        scanf("%d %d",&processes[i].arrival_time,&processes[i].burst_time);
    }
    sortbyarrivaltime(processes, n);
    findtimes(processes, n);
    printresults(processes, n);
    return 0;
}