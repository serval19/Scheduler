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
 
void sortbybursttime(struct process p[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(p[j].burst_time > p[j+1].burst_time){
                struct process temp= p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}


