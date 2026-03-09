#include<stdio.h>

int main()
{
    int n,i,j,time=0,small;
    int at[20],bt[20],ct[20],tat[20],wt[20],done[20]={0};

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
    }

    for(i=0;i<n;i++)
    {
        small=-1;

        for(j=0;j<n;j++)
        {
            if(done[j]==0 && at[j]<=time)
            {
                if(small==-1 || bt[j]<bt[small])
                    small=j;
            }
        }

        if(small==-1)
        {
            time++;
            i--;
            continue;
        }

        time+=bt[small];
        ct[small]=time;
        tat[small]=ct[small]-at[small];
        wt[small]=tat[small]-bt[small];

        done[small]=1;
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);

    return 0;
}
