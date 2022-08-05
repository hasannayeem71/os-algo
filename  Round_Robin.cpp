#include <bits/stdc++.h>

using namespace std;

int main()
{
    int bt[100],tq,i,n,rembt[100],t=0,wt[100],c=0,p[100],tat[100];
    double total=0, avgwt=0;
    printf("Input process number.\n");
    cin>>n;
    for(i=0; i<n; i++)
    {
        printf("Input burst time for process P[%d].\n",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;

    }
    printf("Take Input time quantum.\n");
    cin>>tq;
    for(i=0; i<n; i++)
    {
        rembt[i]=bt[i];
    }
    while(c!=n)
    {
        for(i=0; i<n; i++)
        {

            if(rembt[i]>tq)
            {
                t=t+tq;
                rembt[i]=rembt[i]-tq;
            }
            else if(rembt[i]!=0)
            {
                t=t+rembt[i];
                wt[i]=t-bt[i];
                tat[i]=t;
                total=total+wt[i];
                rembt[i]=0;
                c++;

            }

        }
    }
    avgwt=total/n;
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");

    for(i=0; i<n; i++)
    {
        total=total+bt[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
    double avgtt=total/n;
    printf("\nAverage waiting time %0.2lf\n",avgwt);
    printf("Average turn around time %0.2lf\n",avgtt);


    return 0;
}


