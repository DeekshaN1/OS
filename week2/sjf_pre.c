#include<stdio.h>

int main()
{
    int n,i,time=0,remain,small;
    int at[20],bt[20],rt[20],ct[20],tat[20],wt[20];

    printf("Enter number of processes: ");
    scanf("%d",&n);

    remain=n;

    for(i=0;i<n;i++)
    {
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }

    while(remain!=0)
    {
        small=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]>0)
            {
                if(small==-1 || rt[i]<rt[small])
                    small=i;
            }
        }

        if(small==-1)
        {
            time++;
            continue;
        }

        rt[small]--;
        time++;

        if(rt[small]==0)
        {
            remain--;
            ct[small]=time;
            tat[small]=ct[small]-at[small];
            wt[small]=tat[small]-bt[small];
        }

    }
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    return 0;
}
