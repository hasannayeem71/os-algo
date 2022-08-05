#include<bits/stdc++.h>
using namespace std;
int main ()
{

    int i,n,j,temp,ta=0,min;
    int bt[100],wt[100],tat[100],p[100],at[100],sum=0,btime=0,k=1;
    float awt=0,atat=0;
    printf("Shortest Job First Scheduling Non-Primitive(Varried Arrival)\n");
    printf("Enter the No. of processes :\n");
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        printf("Enter the arrival time of %d process :\n",i+1);
        scanf("%d",&at[i]);

        printf("Enter the burst time of %d process :\n",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }

    /*Sorting According to Burst Time because arrival time is already sorted*/
    for(j=0; j<n; j++)
    {
        btime=btime+bt[j];
        min=bt[k];
        for(i=k; i<n; i++)
        {
            if (at[i]<=btime && bt[i]<min)
            {
                temp=p[k];
                p[k]=p[i];
                p[i]=temp;
                temp=at[k];
                at[k]=at[i];
                at[i]=temp;
                temp=bt[k];
                bt[k]=bt[i];
                bt[i]=temp;
            }
        }
        k++;
    }

    /*waiting time & turnaround time calculation of every process*/

    wt[0]=0;
    // tat[0]=bt[0];
    for(i=1; i<n; i++)
    {
        sum=sum+bt[i-1];
        wt[i]=sum-at[i];
        awt=awt+wt[i];
    }
    for(i=0; i<n; i++)
    {
        ta=ta+bt[i];
        tat[i]=ta-at[i];
        atat=atat+tat[i];
    }
    atat/=n;
    awt/=n;

    printf("Process.\tB.T.\tW.T.\tT.A.T.\n");
    for(i=0; i<n; i++)
    {
        printf("P[%d]\t         %3d\t%3d\t%4d\n",p[i],bt[i],wt[i],tat[i]);
    }
    printf("Average Waiting Time: %0.3f\nAverage Turn Around Time:%0.3f",awt,atat);


    return 0;
}

