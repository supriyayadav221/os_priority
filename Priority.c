#include<conio.h>
#include<stdio.h>
int main()
{
int burst_time[20];
int process_number[20];
int wait_time[20];
int turn_arnd_time[20];
int arrival_time[20];
int priority[20];
int no_of_process;
int total =0;
int temp,flag;
int total_avg_time ,total_avg_turn_arnd_time;
    printf("PRIORITY SCHEDULING\n ");    
printf("Enter the Number of Processes:");
    scanf("%d",&no_of_process);
    printf("\nEnter the Burst Time and Priority of processes\n");
int i;
int j;
for(i=0;i<no_of_process;i++)
    {
        printf("\nProcess[%d]\n",(i+1));
        printf("Enter the Burst Time:");
        scanf("%d",&burst_time[i]);
        printf("Enter the Arrival Time:");
        scanf("%d",&arrival_time[i]);
        printf("Enter the  Priority->");
        scanf("%d",&priority[i]);
        process_number[i]=i+1;
    }

for(i=0;i<no_of_process;i++)
    {
        flag=i;
        for(j=i+1;j<no_of_process;j++)
        {
            if(priority[j]<priority[flag])
            flag=j;
        }
        temp=priority[i];
        priority[i]=priority[flag];
        priority[flag]=temp;
        temp=burst_time[i];
        burst_time[i]=burst_time[flag];
        burst_time[flag]=temp;
        temp=process_number[i];
        process_number[i]=process_number[flag];
        process_number[flag]=temp;
    }

 wait_time[0]=0;  
    for(i=1;i<no_of_process;i++)
    {
        wait_time[i]=0;
        for(j=0;j<i;j++)
            wait_time[i]+=burst_time[j];
        total+=wait_time[i];
    }

 total_avg_time=total/no_of_process;  
    total=0;
    printf("======================================================================================================");
    printf("\nProcess\t    Burst Time           Wait Time          Turn Around Time");
    for(i=0;i<no_of_process;i++)
    {
        turn_arnd_time[i]=burst_time[i]+wait_time[i];  
        total+=turn_arnd_time[i];
        printf("\nProcesses  %d  \t  %d\t  \t    %d\t\t%d",process_number[i],burst_time[i],wait_time[i],turn_arnd_time[i]);
    }
 printf("\n=======================================================================================================");
    total_avg_turn_arnd_time=total/no_of_process;
    printf("\n\nAverage Wait Time= %d",total_avg_time);
    printf("\nAvg TurnAroundTime= %d",total_avg_turn_arnd_time);
    return 0;
}
