#include <stdio.h>

// Function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
    // waiting time for first process is 0
    wt[0] = 0;

    // calculating waiting time
    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

// Function to calculate turn around time
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    // calculating turnaround time by adding
    // bt[i] + wt[i]
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}

// Function to calculate average time
void findavgTime(int processes[], int n, int bt[])
{
    int wt[n], tat[n];

    // Function to find waiting time of all processes
    findWaitingTime(processes, n, bt, wt);

    // Function to find turn around time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat);

    printf("Processes | Burst time | Waiting time | Turn around time\n");

    // Calculate total waiting time and total turn around time
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("    %d     |     %d      |      %d        |       %d\n", (i + 1), bt[i], wt[i], tat[i]);
    }


    float s = (float)total_wt / (float)n;
    float t = (float)total_tat / (float)n;


    printf("Average waiting time = %.2f\n", s);
    printf("Average turn around time = %.2f\n", t);
}

int main()
{
    int numberProcess;
    printf("Enter the number of Processes: ");
    scanf("%d", &numberProcess);

    int processID[numberProcess], burstTime[numberProcess];

    for (int i = 0; i < numberProcess; i++)
    {
        printf("Enter the Process ID: ");
        scanf("%d", &processID[i]);
        printf("Enter the Burst Time: ");
        scanf("%d", &burstTime[i]);
    }

    findavgTime(processID, numberProcess, burstTime);
    return 0;
}
