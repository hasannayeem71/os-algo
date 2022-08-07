#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,i,j,bt[100],pr[100],p[100],wt[100],tat[100],temp;
    float avgtat=0,avgwt=0,total=0;
    printf("Enter the number of processes.\n");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter the burst time for P[%d] process.\n",i+1);
        scanf("%d",&bt[i]);

        printf("Enter the priority for P[%d] process.\n",i+1);
        scanf("%d",&pr[i]);

        p[i]=i+1;
    }


// sorting the processes according to their priority
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(pr[j]<pr[i])
            {
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                temp=pr[i];
                pr[i]=pr[j];
                pr[j]=temp;

                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
// calculating waiting time
    wt[0]=0;
    for(i=1; i<n; i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        total+=wt[i];
    }
    avgwt=total/n;

    // calculating turn around time
    total=0;
    for(i=0; i<n; i++)
    {
        tat[i]=wt[i]+bt[i];
        total+=tat[i];
    }
    avgtat=total/n;

    printf("\nProcess\tBurst Time\tPriority\tW.T.\tTAT\t\n");
    for(i=0; i<n; i++)
    {
        printf("P[%d]  \t  %d\t       %d\t        %d\t  %d\t \n",p[i],bt[i],pr[i],wt[i],tat[i]);
    }
    printf("Average waiting time %0.3f\n",avgwt);
    printf("Average turn around time %0.3f\n",avgtat);



    return 0;
}


// input : 5 10 3 1 1 2 4 1 5 5 2