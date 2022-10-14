#include <stdio.h>
#include <stdlib.h>
typedef struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
    int remaining_time;
} process;
process *p;
process running[1000], queue[1000];
int end = -1;
int front = -1;
void push(process p)
{
    if (front == -1)
    {
        front = 0;
    }
    end++;
    queue[end] = p;
}
void pop()
{
    front++;
}
process front_p()
{
    return queue[front];
}
void merge(process *arr, int l, int mid, int r)
{
    int i, j, k;
    int n1 = mid - l + 1;
    int n2 = r - mid;
    process left[n1], right[n2];
    for (i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (left[i].arrival_time <= right[j].arrival_time)
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}
void mergeSort(process *arr, int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}
process current;
int push_signal = 0;
void roundRobinCPUScheduling(int n, int time_quantum)
{
    int waiting_time = 0, turnaround_time = 0;
    int time = 0;
    int cnt = 0;
    int i = 0;
    while (cnt < n)
    {
        while (i < n && p[i].arrival_time <= time)
        {
            push(p[i++]);
        }
        if (front == -1 || front > end)
        {
            time = p[i].arrival_time;
            continue;
        }
        if (push_signal == 1)
        {
            push(current);
            push_signal = 0;
        }
        current = front_p();
        pop();
        if (current.remaining_time <= time_quantum)
        {
            time += current.remaining_time;
            current.remaining_time = 0;
            current.turnaround_time = time - current.arrival_time;
            current.waiting_time = current.turnaround_time - current.burst_time;
            current.completion_time = time;
            running[cnt] = current;
            cnt++;
            waiting_time += current.waiting_time;
            turnaround_time += current.turnaround_time;
        }
        else
        {
            time += time_quantum;
            current.remaining_time -= time_quantum;
            push_signal = 1;
        }
    }
printf("\n\nProcess ID\t\tBurst Time\t Arrival Time\t Completion Time\t Turnaround Time\t Waiting 
Time\n\n");
for (int i = 0; i < n; i++)
{
        printf("%d\t\t\t%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n", running[i].pid,
               running[i].burst_time, running[i].arrival_time, running[i].completion_time,
               running[i].turnaround_time + running[i].arrival_time, running[i].turnaround_time,
               running[i].waiting_time);
}
printf("\nAverage Waiting Time: %f", (float)waiting_time / n);
printf("\nAverage Turnaround Time: %f\n", (float)turnaround_time / n);
}
int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    p = (process *)malloc(n * sizeof(process));
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details for Process %d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &p[i].burst_time);
        p[i].pid = i + 1;
        p[i].remaining_time = p[i].burst_time;
    }
    int time_quantum;
    printf("\nTime quantum : ");
    scanf("%d", &time_quantum);
    mergeSort(p, 0, n - 1);
    roundRobinCPUScheduling(n, time_quantum);
    return 0;
}
