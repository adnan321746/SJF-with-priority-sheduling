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
