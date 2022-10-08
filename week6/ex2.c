#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sortat(int at[], int bt[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                swap(&at[i], &at[j]);
                swap(&bt[i], &bt[j]);
            }
            else if (at[i] == at[j])
            {
                if (bt[i] > bt[j])
                {
                    swap(&bt[i], &bt[j]);
                }
            }
        }
    }
}

void findWT(int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
    }
}

void findTAT(int n, int ct[], int at[], int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
    }
}

int main()
{
    int n;
    printf("enter number of proccesses: ");
    scanf("%d", &n);

    int arrival_time[n];
    printf("enter arrival time of each process:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arrival_time[i]);
    }

    printf("enter burst time of each process:\n");
    int burst_time[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &burst_time[i]);
    }

    int key, j;
    int waiting_time[n], turnaround_time[n], compl_time[n];

    sortat(arrival_time, burst_time, n);
    compl_time[0] = burst_time[0] + arrival_time[0];

    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arrival_time[j] <= compl_time[i - 1])
            {
                if (burst_time[j] < burst_time[i])
                {
                    swap(&arrival_time[j], &arrival_time[i]);
                    swap(&compl_time[i], &compl_time[j]);
                    swap(&burst_time[i], &burst_time[j]);
                }
            }
        }
        if (arrival_time[i] < compl_time[i - 1])
        {
            compl_time[i] = compl_time[i - 1] + burst_time[i];
        }
        else
        {
            compl_time[i] = burst_time[i] + arrival_time[i];
        }
    }

    findTAT(n, compl_time, arrival_time, turnaround_time);

    findWT(n, burst_time, waiting_time, turnaround_time);

    int total_wt = 0, total_tat = 0;
    printf("Number of proccess: AT, BT, CT, TAT, WT\n");
    for (int i = 0; i < n; i++)
    {
        total_wt += waiting_time[i];
        total_tat += turnaround_time[i];
        int compl_time = turnaround_time[i] + arrival_time[i];
        printf("%d process: %d, %d, %d, %d, %d\n", i + 1, arrival_time[i], burst_time[i], compl_time, turnaround_time[i], waiting_time[i]);
    }
    printf("Average Turnaround time: %f\n", (float)total_tat / (float)n);
    printf("Average waiting time: %f\n", (float)total_wt / (float)n);

    return 0;
}
