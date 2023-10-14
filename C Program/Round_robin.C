#include <stdio.h>
#include <stdbool.h>

// Function to calculate turn around time
int turnarroundtime(int processes[], int n, int bt[], int wt[]) {
   int tat[n];
   for (int i = 0; i < n; i++) {
      tat[i] = bt[i] + wt[i];
   }
   return 0;
}

// Function to find the waiting time for all processes
int waitingtime(int processes[], int n, int bt[], int wt[], int quantum) {
   int rem_bt[n];
   for (int i = 0; i < n; i++) {
      rem_bt[i] = bt[i];
   }
   int t = 0; // Current time
   bool done = false;
   while (!done) {
      done = true;
      for (int i = 0; i < n; i++) {
         if (rem_bt[i] > 0) {
            done = false;
            if (rem_bt[i] > quantum) {
               t += quantum;
               rem_bt[i] -= quantum;
            } else {
               t += rem_bt[i];
               wt[i] = t - bt[i];
               rem_bt[i] = 0;
            }
         }
      }
   }
   return 0;
}

// Function to calculate average time
int findavgTime(int processes[], int n, int bt[], int quantum) {
   int wt[n], tat[n], total_wt = 0, total_tat = 0;
   waitingtime(processes, n, bt, wt, quantum);
   turnarroundtime(processes, n, bt, wt);

   for (int i = 0; i < n; i++) {
      total_wt += wt[i];
      total_tat += tat[i];
   }

   float avg_wt = (float)total_wt / (float)n;
   float avg_tat = (float)total_tat / (float)n;

   printf("Processes Burst Time Waiting Time Turnaround Time\n");
   for (int i = 0; i < n; i++) {
      printf(" %d\t\t %d\t\t %d\t\t %d\n", i + 1, bt[i], wt[i], tat[i]);
   }

   printf("Average waiting time = %f\n", avg_wt);
   printf("Average turnaround time = %f\n", avg_tat);

   return 0;
}

// Main function
int main() {
   int processes[] = {1, 2, 3};
   int n = sizeof(processes) / sizeof(processes[0]);
   int bt[] = {8, 6, 12};
   int quantum = 2;

   findavgTime(processes, n, bt, quantum);

   return 0;
}