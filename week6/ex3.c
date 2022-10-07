#include <stdio.h>
#include <stdbool.h>

bool remainders(int rem_time[], int n)
{
    int remainder = 0;
    for (int i = 0; i < n; i++)
    {
        remainder += rem_time[i];
    }
    return remainder > 0 ? true : false;
}

int main()
{
    int current = 0, n, time = 0, time_quantum;
    bool f = false;
    int wait_time = 0, turnaround_time = 0;

    printf("enter number of proccesses: ");
    scanf("%d", &n);

    int arrival_time[n], burst_time[n], remain_time[n];
    int remain = n;

    printf("enter arrival time of each process:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arrival_time[i]);
    }

    printf("enter burst time of each process:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &burst_time[i]);
        remain_time[i] = burst_time[i];
    }

    printf("Enter Time Quantum:\n");
    scanf("%d", &time_quantum);

    printf("Number of proccess: AT, BT, CT, TAT, WT\n");

    while (remain != 0)
    {
        if (remain_time[current] <= time_quantum && remain_time[current] > 0)
        {
            time += remain_time[current];
            remain_time[current] = 0;
            f = true;
        }
        else if (remain_time[current] > 0)
        {
            remain_time[current] -= time_quantum;
            time += time_quantum;
        }
        if (remain_time[current] == 0 && f)
        {
            remain--;
            int tat = time - arrival_time[current];
            int wt = time - arrival_time[current] - burst_time[current];
            printf("%d process: %d, %d, %d, %d, %d\n", current + 1, arrival_time[current], burst_time[current], time, tat, wt);
            wait_time += wt;
            turnaround_time += tat;
            f = false;
        }
        if (current == n - 1)
            current = 0;
        else if (arrival_time[current + 1] <= time)
            current++;
        else if (arrival_time[current + 1] > time && !remainders(remain_time, current + 1))
        {
            time = arrival_time[current + 1];
        }
        else
            current = 0;
    }

    printf("Average Turnaround time: %f\n", (float)wait_time / (float)n);
    printf("Average waiting time: %f\n", (float)turnaround_time / (float)n);

    return 0;
}