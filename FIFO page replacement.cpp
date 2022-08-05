#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int i,j=0,k,n,rs[100],frame[10],len,count=0,avail;
    printf("Enter the length of a reference string.\n");
    scanf("%d",&len);
    printf("Enter the reference string.\n");
    for(i=0; i<len; i++)
    {
        scanf("%d",&rs[i]);
    }
    printf("Enter the frame size.\n");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        frame[i] = -1;
    }

    for(i=0; i<len; i++)
    {
        printf("\n%4d\t", rs[i]);
        avail = 0;
        for(k=0; k<n; k++)
        {
            if(frame[k] == rs[i])
            {
                avail = 1;
            }

        }

        if(avail == 0)
        {
            frame[j] = rs[i];
            j = (j+1) % n;
            count++;
            for(k=0; k<n; k++)
            {
                printf("%4d", frame[k]);
            }

        }
    }
    printf("\n\nTotal no. of page faults : %d\n",count);

return 0;
}


