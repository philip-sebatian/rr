// Round Robin CPU scheduling algorithm implementation in C!

#include<stdio.h>
#define max 20 // maximum size for array
void main()
{
    int i,burstTime[max],remainTime[max],remainProcess,arrivalTime[max],totalExecutionTime=0,timeQuantum,flag=0,n;
    float totalWaitingTime=0;
    printf("Enter the Number of Process(max 20) : ");
    scanf("%d",&n); // n is the number of Process
    remainProcess=n;

    printf("Enter Arrival Time\n");
    for(i=0;i<n;i++){
        printf("For P[%d]: ",i+1);
        scanf("%d",&arrivalTime[i]);
    }

    printf("\nEnter Burst Time\n");
    for(i=0;i<n;i++){
        printf("For P[%d]: ",i+1);
        scanf("%d",&burstTime[i]);
        remainTime[i]=burstTime[i]; // initially assume remain time for any process is equal to it's burst time !
    }

    printf("\nEnter Time Quantum :");
    scanf("%d",&timeQuantum);

    printf("\n");
    for(i=0;remainProcess!=0;){
        /**
            * this below condition check the remain time for any process is less than or equal with the time quantum
            * or not and also check the remain time is greater than 0 or not. if both condition are true that means
            * the process can execute fully at one time.
        */
        if(remainTime[i]<=timeQuantum && remainTime[i]>0){
            totalExecutionTime+=remainTime[i];
            remainTime[i]=0;
            flag=1;
        }

        else if(remainTime[i]>0){
            remainTime[i]-=timeQuantum;
            totalExecutionTime+=timeQuantum;
        }

        if(flag==1 && remainTime[i]==0){
            printf("P[%d] | waiting Time : %d\n",i+1,totalExecutionTime-arrivalTime[i]-burstTime[i]);
            totalWaitingTime+=totalExecutionTime-arrivalTime[i]-burstTime[i];
            flag=0;
            remainProcess--;
        }

        if(i==n-1)
            i=0;
        else if(arrivalTime[i+1]<=totalExecutionTime){
            i++;
        }
        else
            i=0;
    }

    totalWaitingTime=(float)totalWaitingTime/n;
    printf("\nThe Average Waiting Time : %.2f \n",totalWaitingTime);



}
