/* First Come First Serve CPU Scheduling Algorithm */

#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int wt[10],bt[10],at[10],tat[10],n,i;
    float awt=0,atat=0;
    printf("Enter Number of processes:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter Burst Time of process %d:",i+1);
        scanf("%d",&bt[i]);
    }
    // beacuse who came first doesn't have waiting time
    wt[0]=0;
    tat[0]=bt[0];
    for(i=1; i<n; i++)
    {
        wt[i]=bt[i-1]+wt[i-1];
        awt+=wt[i];
        tat[i]= wt[i]+bt[i];
        atat+=tat[i];
    }
    atat+=bt[0];
    atat/=n;
    awt/=n;

    printf("Process.\tB.T.\tW.T.\tT.A.T.\n");
    for(i=0; i<n; i++)
    {
        printf("P[%d]\t         %3d\t%3d\t%4d\n",i+1,bt[i],wt[i],tat[i]);
    }
    printf("Average Waiting Time: %0.3f\nAverage Turn Around Time:%0.3f",awt,atat);

    return 0;
}



// input should be like this:

// Enter Number of processes:3
// Enter Burst Time of process 1: 24  
// Enter Burst Time of process 2: 3
// Enter Burst Time of process 3: 3
