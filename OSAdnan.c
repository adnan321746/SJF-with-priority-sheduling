 /*Consider a scheduling approach which is non pre-emptive similar to shortest job next in nature. 
 The priority of each job is dependent on its estimated run time, and also the amount of time it 
 has spent waiting. Jobs gain higher priority the longer they wait, which prevents indefinite postponement. 
 The jobs that have spent a long time waiting compete against those estimated to have short run times. 
 The priority can be computed as :  priority = 1 + waiting time /estimated run time 
 Using the data given below compute the waiting time and turnaround time for each process and 
 average waiting time and average turnaround time. */

#include<stdio.h>
int main()
{
int i,n,p[10]={1,2,3,4,5,6,7,8,9,10},k=1,btime=0;
int bt[10],tt[10],ta=0,sum=0,j,at[10],wt[10];
float tavg=0,tsum=0,wavg=0,temp,wsum=0,prr[10];

printf(" -------Code by Adnan Khan -------\n");
printf("\nEnter the No. of processes :");
scanf("%d",&n);
 
for(i=0;i<n;i++)
{
printf("\n\tEnter the burst time of %d process :",i+1);
scanf(" %d",&bt[i]);
printf("\tEnter the arrival time of %d process :",i+1);
scanf(" %d",&at[i]);
 
}
 /*Sorting According to Arrival Time*/
 
for(i=0;i<n;i++)
{
for(j=1;j<n;j++)
{
if(at[i]>at[j])
{
temp=p[j];
p[j]=p[i];
p[i]=temp;
temp=at[j];
at[j]=at[i];
at[i]=temp;
temp=bt[j];
bt[j]=bt[i];
bt[i]=temp;
}
}
}
  
/*Sorting according to Burst time,
Execution time and Arrival Time*/
 
for(j=0;j<n;j++)
{
btime=btime+bt[j];
min=bt[k];
for(i=k;i<n;i++)
{
if (btime>=at[i] && bt[i]<min)
{
temp=p[k];
p[k]=p[i];
p[i]=temp;
temp=at[k];
at[k]=at[i];
at[i]=temp;
temp=bt[k];
bt[k]=bt[i];
bt[i]=temp;
}
}
k++;
}
wt[0]=0;
for(i=1;i<n;i++)
{
sum=sum+bt[i-1];
wt[i]=sum-at[i];
wsum=wsum+wt[i];
}
 printf("----------------------------------------------------------------------------------------------------------------------------->");

printf("\nProcess\t        Burst\t Arrival\t Waiting\t Turn-around\t    Priority" );
for(i=0;i<n;i++)
{
printf("\n process:%d\t %d\t %d\t\t %d\t\t\t%d \t\t%f",p[i],bt[i],at[i],wt[i],tt[i],prr[i]);
}
 
printf("\n\nAVERAGE WAITING TIME : %f",wavg);
printf("\nAVERAGE TURN AROUND TIME : %f",tavg);
return 0;
}
}
