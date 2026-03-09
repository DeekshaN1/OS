#include<stdio.h>

int main()
{
    int n,i,j,time=0,high;
    int at[20],bt[20],pr[20],ct[20],tat[20],wt[20],done[20]={0};

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter AT BT Priority for P%d: ",i+1);
        scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
    }

    for(i=0;i<n;i++)
    {
        high=-1;

        for(j=0;j<n;j++)
        {
            if(done[j]==0 && at[j]<=time)
            {
                if(high==-1 || pr[j]<pr[high])
                    high=j;
            }
        }

        if(high==-1)
        {
            time++;
            i--;
            continue;
        }

        time+=bt[high];
        ct[high]=time;
        tat[high]=ct[high]-at[high];
        wt[high]=tat[high]-bt[high];

        done[high]=1;
    }

    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);

    return 0;
}
