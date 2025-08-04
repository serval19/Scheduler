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