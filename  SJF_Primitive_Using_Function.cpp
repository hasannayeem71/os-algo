#include <bits/stdc++.h>
using namespace std;
struct Process
{
int art;
int bt;
};
void findTurnAroundTime(Process proc[], int n, int wt[], int tat[])
{
for (int i = 0; i < n; i++)
tat[i] = proc[i].bt + wt[i];
}
void findWaitingTime(Process proc[], int n, int wt[])
{
int rt[n];
for (int i = 0; i < n; i++)
rt[i] = proc[i].bt;
int complete = 0, t = 0, minm = INT_MAX;
int shortest = 0, finish_time;

while (complete != n)
{
for (int j = 0; j < n; j++)
{
if ((proc[j].art <= t) && (rt[j] < minm) && rt[j] > 0)
{ minm = rt[j];
shortest = j;
}
}
if(rt[shortest]!=0)
{ rt[shortest]--;
minm = rt[shortest];
if (minm == 0)
minm = INT_MAX;
if (rt[shortest] == 0)
{
complete++;
finish_time = t + 1;
wt[shortest] = finish_time - proc[shortest].bt - proc[shortest].art;
if (wt[shortest] < 0)
wt[shortest] = 0;
}
}
t++;
} }

void findavgTime(Process proc[], int n)
{
int wt[n], tat[n], total_wt = 0,total_tat = 0;
findWaitingTime(proc, n, wt);
findTurnAroundTime(proc, n, wt, tat);
cout << "Processes " << " Arrival time " << " Burst time " << " Waiting time " << " Turn
around time\n";
for (int i = 0; i < n; i++)
{
total_wt = total_wt + wt[i];
total_tat = total_tat + tat[i];
cout << "P[" << i+1 <<"]"<< "\t\t" <<proc[i].art<< "\t\t "<< proc[i].bt << "\t\t " << wt[i] <<
"\t\t " << tat[i] << endl;
}
cout << "\nAverage waiting time = " << (float)total_wt / (float)n;
cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}
int main()
{
int n,i;
struct Process proc[1000];
printf("Enter the number of processes\n");
scanf("%d",&n);

for(i=0; i<n; i++)
{
printf("Enter p[%d] process arrival time\n",i+1);
scanf("%d",&proc[i].art);
printf("Enter p[%d] process burst time\n",i+1);
scanf("%d",&proc[i].bt);
}
findavgTime(proc, n);
return 0;
}