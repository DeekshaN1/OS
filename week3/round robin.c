#include <stdio.h>

int main() {
    int n, tq;
    int at[20], bt[20], rt[20];
    int wt[20], tat[20], ct[20];
    int i, time = 0, remain, flag = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i]; // remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    remain = n;

    while(remain > 0) {
        flag = 0;
        for(i = 0; i < n; i++) {

            if(at[i] <= time && rt[i] > 0) {

                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                }
                else {
                    time += rt[i];
                    ct[i] = time;
                    rt[i] = 0;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];

                    avg_wt += wt[i];
                    avg_tat += tat[i];

                    remain--;
                }
                flag = 1;
            }
        }

        if(flag == 0) {
            time++;
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", avg_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt / n);

    return 0;
}
