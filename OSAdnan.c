 /*Consider a scheduling approach which is non pre-emptive similar to shortest job next in nature. 
 The priority of each job is dependent on its estimated run time, and also the amount of time it 
 has spent waiting. Jobs gain higher priority the longer they wait, which prevents indefinite postponement. 
 The jobs that have spent a long time waiting compete against those estimated to have short run times. 
 The priority can be computed as :  priority = 1 + waiting time /estimated run time 
 Using the data given below compute the waiting time and turnaround time for each process and 
 average waiting time and average turnaround time. */
 
 #include<stdio.h>
 #include<conio.h>
 #include<stdlib.h>
 
int main()
{
int i,n,p[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,btime=0,again=1,prr[10];
int bt[10],temp,j,at[10],wt[10],tt[10],ta=0,sum=0;
float wavg=0,tavg=0,tsum=0,wsum=0;
printf(" CODE BY ADNAN KHAN-------\n");
while(again==1)
{


printf("\nEnter the No. of processes :");
scanf("%d",&n);
 
for(i=0;i<n;i++)
{
printf("\n\tEnter the burst time of %d process :",i+1);
scanf(" %d",&bt[i]);
printf("\t Enter the arrival time of %d process :",i+1);
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
if (btime>at[i] && bt[i]<min)
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
// sorting according to calculated priority 

for(i=1;i<n;i++)
{
	prr[i]=1+(wt[i]/bt[i]);
	prr[0]=0;
}
for(i=2;i<n;i++)
{
for(j=3;j<n;j++)
{

if(prr[i]>prr[j])
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
temp=prr[j];
prr[j]=prr[i];
prr[i]=temp;
temp=wt[j];
wt[j]=wt[i];
wt[i]=temp;
}
}
}
 
wavg=(wsum/n);
for(i=0;i<n;i++)
{
ta=ta+bt[i];
tt[i]=ta-at[i];
tsum=tsum+tt[i];
}
 
tavg=(tsum/n);
 
 printf("----------------------------------------------------------------------------------------------------------------------------->");


printf("\n\nProcess\t     Burst\t Arrival\t Waiting\t Turn-around   \t priority" );
for(i=0;i<n;i++)
{
printf("\nprocess: %d\t %d\t %d\t\t %d\t\t\t%d \t\t %d",p[i],bt[i],at[i],wt[i],tt[i],prr[i]);
}
 
printf("\n\nAVERAGE WAITING TIME : %f",wavg);
printf("\nAVERAGE TURN AROUND TIME : %f",tavg);
printf("\n\n\PRESS 1 FOR RESTART THE PROGRAM \tPRESS ANYTHING FOR EXIT : ");
scanf("%d",&again);
system("cls");
}
}
