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
		}
	}
}

void findWT(int n, int bt[], int wt[], int at[])
{
	int sum_time[n];
	sum_time[0] = at[0];
	wt[0] = 0;

	for (int i = 1; i < n; i++)
	{
		sum_time[i] = sum_time[i - 1] + bt[i - 1];
		wt[i] = sum_time[i] - at[i] > 0 ? sum_time[i] - at[i] : 0;
	}
}

void findTAT(int n, int bt[], int wt[], int tat[])
{
	for (int i = 0; i < n; i++)
	{
		tat[i] = bt[i] + wt[i];
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
	int waiting_time[n], turnaround_time[n];

	sortat(arrival_time, burst_time, n);

	// for (int i = 1; i < n; i++)
	// {
	// 	key = arrival_time[i];
	// 	j = i - 1;
	// 	while (j >= 0 && arrival_time[j] > key)
	// 	{
	// 		arrival_time[j + 1] = arrival_time[j];
	// 		burst_time[j + 1] = burst_time[j];
	// 		j -= 1;
	// 	}
	// 	arrival_time[j + 1] = key;
	// }

	findWT(n, burst_time, waiting_time, arrival_time);

	findTAT(n, burst_time, waiting_time, turnaround_time);

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
