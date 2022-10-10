#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


int i, j, total_time = 0;
float total_tat = 0, total_wt = 0;
int queue[100];
int cur_time = 0, front = 0, rear = 0, k = 0;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void push(int num)
{
    queue[rear++] = num;
}

int getElem()
{
    return queue[front++];
}

void check_at(int at[], int n)
{
    while (at[j] <= cur_time && j < n)
    {
        k++;
        push(j++);
    }
}
void finding(int at[], int bt[], int wt[], int ct[], int n, int q)
{
    int temp_bt[n], count = 0, p = 0;
    bool flag = false;
    j = 0;
    for (int i = 0; i < n; i++)
    {
        temp_bt[i] = bt[i];
    }
    cur_time = at[0];
    k = 1;
    push(j++);
    while (cur_time <= total_time)
    {
        if (flag || k != 0)
        { 
            if (!flag && count == 0)
            {
                p = getElem();
                count = 0;
                flag = true;
            }
            temp_bt[p]--;
            if (temp_bt[p] == 0)
            {
                cur_time++;
                count = 0;
                ct[p] = cur_time;
                flag = false;
                k--;
                check_at(at, n);
                continue;
            }

            count++;
            if (count == q)
            {
                count = 0;
                cur_time++;
                check_at(at, n);
                push(p);
                flag = false;
            }
            else
            {
                cur_time++;
                check_at(at, n);
            }
        }
        else
        {
            cur_time++;
            check_at(at, n);
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int arrival_time[n], burst_time[n], waiting_time[n], turnaround_time[n], compl_time[n];
    float ntat[n];

    printf("enter arrival time of each process:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arrival_time[i]);
    }

    printf("enter burst time of each process:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &burst_time[i]);
    }

    int quantum;
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            if (arrival_time[j] < arrival_time[j - 1])
            {
                swap(&arrival_time[j], &arrival_time[j - 1]);
                swap(&burst_time[j], &burst_time[j - 1]);
            }
        }
    }


    total_time += arrival_time[0] + burst_time[0];
    for (int i = 1; i < n; i++)
    {
        if (total_time < arrival_time[i])
        {
            total_time = arrival_time[i];
        }
        total_time += burst_time[i];
    }

    finding(arrival_time, burst_time, waiting_time, compl_time, n, quantum);

    printf("Number of proccess: AT, BT, CT, TAT, WT\n");
    for (int i = 0; i < n; i++)
    {
        turnaround_time[i] = compl_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
        ntat[i] = (float)turnaround_time[i] / burst_time[i];
        printf("%d process: %d, %d, %d, %d, %d\n", i + 1, arrival_time[i], burst_time[i], compl_time[i], turnaround_time[i], waiting_time[i]);
        total_tat += turnaround_time[i];
        total_wt += waiting_time[i];
    }

    printf("Average Turnaround time: %f\n", (float) total_tat / (float) n);
    printf("Average waiting time: %f\n", (float) total_wt / (float) n);
}