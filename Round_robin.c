#include<stdio.h>

void WaitingTime(int n, int BT[], int REM_BT[], int WT[], int PID[])
{
    int t = 0, count = 0;
    int quan = 4;

    while (count != n)
    {
        for (int i = 0; i < n; i++)
        {

        if(REM_BT[i] <= 0)
        {
            continue;
        }

           else if ( REM_BT[i] > quan)
            {

                t += quan;
                REM_BT[i] -= quan;
            }
            else
            {
                t += REM_BT[i];
                WT[i] = t - BT[i];
                REM_BT[i] = 0;
                count++;
            }
        }
    }
}


void TurnArroundTime(int n, int PID[],  int BT[], int WT[], int TAT[])
{
    for (int i = 0; i < n ; i++)
    {
        TAT[i] = BT[i] + WT[i];
    }
}

void printAll(int n ,int PID[], int BT[] , int WT[] , int TAT[])
{
    printf ("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0 ; i<n ;i++)
    {
        printf ("P%d\t\t%d\t\t%d\t\t%d\n",PID[i],BT[i],WT[i],TAT[i]);
    }
}

void average(int n ,int WT[] , int TAT[])
{
    float TWT = 0 , TTAT = 0 , AWT , ATAT ;
    for(int i=0 ; i<n ; i++)
    {
       TWT += WT[i];
       TTAT += TAT[i];
    }
    AWT = TWT/n;
    ATAT = TTAT/n;

    printf ("\n\nAverage waiting time : %.2f" ,AWT);
    printf ("\nAverage turn around time : %.2f\n\n" ,ATAT);
}

main()
{
    int n;
    printf("Enter the number of process : ");
    scanf ("%d",&n);


    int PID[n] , BT[n] , REM_BT[n], WT[n] , TAT[n] ;
    for(int i=0 ; i < n ; i++)
    {
        printf("Enter the process ID : ");
        scanf("%d",&PID[i]);
        printf("Burst time P%d : ",PID[i]);
        scanf("%d",&BT[i]);
        REM_BT[i]= BT[i];

    }

    WaitingTime(n , BT , REM_BT , WT, PID);
    TurnArroundTime(n, PID, BT, WT, TAT);
    printAll(n ,PID, BT,WT, TAT);
    average(n ,WT, TAT);
}
