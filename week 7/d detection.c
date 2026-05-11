#include <stdio.h>
int main()
{
    int n, m, i, j, k;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);
    int allocation[n][m], request[n][m];
    int available[m];
    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }
    printf("\nEnter Request Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &request[i][j]);
        }
    }
    printf("\nEnter Available Vector:\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
    }
    int work[m], finish[n];
    for(i = 0; i < m; i++)
    {
        work[i] = available[i];
    }
    for(i = 0; i < n; i++)
    {
        int sum = 0;
        for(j = 0; j < m; j++)
        {
            sum += allocation[i][j];
        }
        if(sum == 0)
            finish[i] = 1;
        else
            finish[i] = 0;
    }
    int found;
    do
    {
        found = 0;
        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int possible = 1;
                for(j = 0; j < m; j++)
                {
                    if(request[i][j] > work[j])
                    {
                        possible = 0;
                        break;
                    }
                }
                if(possible)
                {
                    for(k = 0; k < m; k++)
                    {
                        work[k] += allocation[i][k];
                    }
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
    } while(found);
    int deadlock = 0;
    printf("\n");
    for(i = 0; i < n; i++)
    {
        if(finish[i] == 0)
        {
            deadlock = 1;
            printf("Process P%d is deadlocked.\n", i);
        }
    }
    if(deadlock == 0)
    {
        printf("No Deadlock Detected.\n");
    }
    return 0;
}
