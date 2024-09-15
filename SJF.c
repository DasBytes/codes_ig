#include <stdio.h>
void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}
void findAvgTime(int processes[], int n, int bt[])
{
    int wt[n], tat[n];

    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);

    printf("Processes | Burst time | Waiting time | Turn around time\n");
    printf("----------------------------------------------------------\n");

    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf(" %d   \t| %d   \t| %d   \t| %d\n", processes[i], bt[i], wt[i], tat[i]);
    }
    printf("----------------------------------------------------------\n");


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


for (int i = 0; i < numberProcess - 1; i++)  // bubble sort
    {
        for (int j = 0; j < numberProcess - i - 1; j++)
        {
            if (burstTime[j] > burstTime[j + 1])
            {

                int temp = burstTime[j];
                burstTime[j] = burstTime[j + 1];
                burstTime[j + 1] = temp;

                int temp2 = processID[j];
                processID[j] = processID[j + 1];
                processID[j + 1] = temp2;
            }
        }
    }
    findAvgTime(processID, numberProcess, burstTime);
    return 0;
}
