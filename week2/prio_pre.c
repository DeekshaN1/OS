#include<stdio.h>

int main()
{
    int n,i,time=0,remain,high;
    int at[20],bt[20],pr[20],rt[20],ct[20],tat[20],wt[20];
    float avgtat,avgwt,ttat=0,twt=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    remain=n;

    for(i=0;i<n;i++)
    {
        printf("Enter AT BT Priority for P%d: ",i+1);
        scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
        rt[i]=bt[i];
    }

    while(remain!=0)
    {
        high=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]>0)
            {
                if(high==-1 || pr[i]<pr[high])
                    high=i;
            }
        }

        if(high==-1)
        {
            time++;
            continue;
        }

        rt[high]--;
        time++;

        if(rt[high]==0)
        {
            remain--;
            ct[high]=time;
            tat[high]=ct[high]-at[high];
            wt[high]=tat[high]-bt[high];
        }
    }
    for(i=0;i<n;i++)
    {
        ttat=ttat+tat[i];
        twt=twt+wt[i];
    }
    avgtat=ttat/n;
    avgwt=twt/n;
    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
    printf("Avarage TAT:%f",avgtat);
    printf("Avarage WT:%f",avgwt);
    return 0;
}

