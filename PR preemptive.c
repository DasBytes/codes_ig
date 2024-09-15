#include <stdio.h>

// Function declarations
void waitingTime(int n, int P[], int AT[], int BT[], int WT[], int Pr[]);
void turnAroundTime(int n, int BT[], int WT[], int TT[]);
void printArr(int n, int P[], int Pr[], int BT[], int WT[], int TT[], int AT[]);

int main()
{
    int n;
    printf("Enter the total number of processes: ");
    scanf("%d", &n);
    int P[n], Pr[n], BT[n], WT[n], AT[n], TT[n];


    for(int i = 0; i < n; i++)
    {
         printf("\nEnter the Process ID: ");
        scanf("%d", &P[i]);
        printf("And priority for P%d?\n", P[i]);
        scanf("%d", &Pr[i]);
        printf("And Burst time for P%d?\n", P[i]);
        scanf("%d", &BT[i]);
        printf("And Arrival time for P%d?\n", P[i]);
        scanf("%d", &AT[i]);
    }

    waitingTime(n, P, AT, BT, WT, Pr);
    turnAroundTime(n, BT, WT, TT);
    printArr(n, P, Pr, BT, WT, TT, AT);

    return 0;
}

void waitingTime(int n, int P[], int AT[], int BT[], int WT[], int Pr[])
{
    int rem_bt[n];
    for (int i = 0; i < n; i++)
    {
        rem_bt[i] = BT[i];
    }

    int completed = 0;
    int t = 0;

    while (completed < n)
    {
        int s = -1;
        int m = 50;

        for (int i = 0; i < n; i++)
        {
            if (AT[i] <= t && rem_bt[i] > 0)
            {
                if(Pr[i] < m)
                {
                    m = Pr[i];
                    s = i;
                }
                else if(Pr[i] == m)
                {
                    if(AT[i] < AT[s])
                    {
                        s = i;
                    }
                    else if(AT[i] > AT[s])
                    {
                        continue;
                    }
                    else
                    {
                        if(P[i] < P[s])
                        {
                            s = i;
                        }
                    }
                }
            }
        }

        if (s == -1)
        {
            t++;
            continue;
        }



        rem_bt[s]--;

        if (rem_bt[s] == 0)
        {
            completed++;
            WT[s] = t + 1 - AT[s] - BT[s];
            if (WT[s] < 0) {
                WT[s] = 0;  // Ensure no negative waiting times
            }
        }

        t++;
    }
    printf("\n");
}

void turnAroundTime(int n, int BT[], int WT[], int TT[])
{
    for(int i = 0; i < n; i++)
    {
        TT[i] = BT[i] + WT[i];
    }
}

void printArr(int n, int P[], int Pr[], int BT[], int WT[], int TT[], int AT[])
{
    printf("ProcessId\tPriority\tBurst\tWaiting\tTurn Around\tArrival\n");
    for(int i = 0; i < n; i++)
    {
        printf("P%d\t\t%d\t\t%d\t%d\t%d\t\t%d\n", P[i], Pr[i], BT[i], WT[i], TT[i], AT[i]);
    }
}
