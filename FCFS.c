#include <stdio.h>
// Function to find the waiting time for all processes
int waitingTime(int process[], int n,
int burst[], int wait[]) {
   // waiting time for first process is 0
   wait[0] = 0;
   // calculating waiting time
   for (int i = 1; i < n ; i++ )
   wait[i] = burst[i-1] + wait[i-1] ;
   return 0;
}

// Function to calculate turn around time
int turnAroundTime( int process[], int n,
int burst[], int wait[], int turnAround[]) {
   /* calculating turnaround time by adding burst_time[i] + wait_time[i] */
   int i;
   for ( i = 0; i < n ; i++)
   turnAround[i] = burst[i] + wait[i];
   return 0;
}

//Function to calculate average time
int avgTime( int process[], int n, int burst[]) {
   int wait[n], turnAround[n], totalWait = 0, totalTurnAround = 0;
   int i;
   //Function to find waiting time of all processes
   waitingTime(process, n, burst, wait);
   //Function to find turn around time for all processes
   turnAroundTime(process, n, burst, wait, turnAround);
   //Display processes along with all details
   printf("Processes | Burst |  Waiting | Turn Around \n");
   // Calculate total waiting time and total turn
   // around time
   for ( i=0; i<n; i++) {
      totalWait = totalWait + wait[i];
      totalTurnAround = totalTurnAround + turnAround[i];
      printf(" %d\t  %d\t\t %d \t%d\n", i+1, burst[i], wait[i], turnAround[i]);
   }
   printf("Average waiting time = %f\n", (float)totalWait / (float)n);
   printf("Average turn around time = %f\n", (float)totalTurnAround / (float)n);
   return 0;
}
// main function
int main() {
   //ID processes
   int process[] = { 1, 2, 3};
   int n = sizeof process / sizeof process[0];

   //Burst times for the order P1, P2, P3
   printf("First instance:\n");
   int burst[] = {5, 8, 12};
   avgTime(process, n, burst);
   printf("\n");

   //Burst times for the order P2, P3, P1
   printf("Second instance:\n");
   int burst2[] = {8, 12, 5};
   avgTime(process, n, burst2);

   return 0;
}

/* 
Observations:
For the first instance of the test values, where the process with the shorter burst
times are loaded first, the average waiting time and the
average turn around time are both smaller than those of the second test instance,
where the processes with longer burst times are executed before the one with the
shorter burst time.

Conclusion:
It is more efficient to load the processes with shorter burst times before those
with longer burst times.
*/