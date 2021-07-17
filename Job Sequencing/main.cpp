#include <iostream>
using namespace std;
int main()
{
    int jobs,i,j,k,temp1,temp2,temp3,highest,total_profit=0;
    cout<<"\t\tJOB SEQUENCING\n";
    cout<<"\nEnter the number of Jobs: ";cin>>jobs;
    int deadlines[jobs],profit[jobs],totaljob[jobs];
    
    cout<<"\nEnter the Profits:\n";
    for(i=0;i<jobs;i++){
        cin>>profit[i];
    }
    cout<<"\nEnter the Deadlines:\n";
    for(i=0;i<jobs;i++){
        cin>>deadlines[i];
    }
    for(i=0;i<jobs;i++){
    
    totaljob[i]=i+1;
    }

    
     for(i=0;i<jobs;i++)
    {   
        for(j=i+1;j<jobs;j++)
        {
            if(profit[i]<profit[j])
            {
                temp1=profit[i];temp2=deadlines[i];temp3=totaljob[i];
                profit[i]=profit[j];deadlines[i]=deadlines[j];totaljob[i]=totaljob[j];
                profit[j]=temp1;deadlines[j]=temp2;totaljob[j]=temp3;
            }
        } 
    }
    
    cout<<"\n\nJob No: ";
    for(i=0;i<jobs;i++){
        cout<<"\tJ"<<totaljob[i];
    }
    cout<<"\nProfits: ";
    for(i=0;i<jobs;i++){
        cout<<"\t"<<profit[i];
    }
    cout<<"\nDeadlines: ";
    for(i=0;i<jobs;i++){
        cout<<"\t"<<deadlines[i];
    }
    
    
     highest = deadlines[0];
     for(i=1;i<jobs;i++) {
      
      if(highest<deadlines[i])
         highest=deadlines[i];
   }
 
   int gantt[highest];
   
   for(i=0;i<highest;i++){
       gantt[i]=0;     
   }
   
   for(i=0;i<jobs;i++){
       for(j=1;j<=highest;j++){
           if(deadlines[i]==j){
               if(gantt[j-1]==0){
                   gantt[j-1]=totaljob[i];
                   total_profit=total_profit+profit[i]; 
               }
               else{
                   for(k=j-1;k>=0;--k){
                       if(gantt[k]==0){
                           gantt[k]=totaljob[i];
                           total_profit=total_profit+profit[i];
                       }
                       else{
                           continue;
                       }
                   }
               }
            }
           else
           {
               continue;
           }
       }
       
   }
    cout<<"\n\nGantt Chart: ";
   for(i=0;i<highest;i++){
       cout<<"\tJ"<<gantt[i];
   }  for(i=0;i<highest;i++)
    {   
        for(j=i+1;j<highest;j++)
        {
            if(gantt[i]>gantt[j])
            {
                temp1=gantt[i];gantt[i]=gantt[j];gantt[j]=temp1;
    }
        }
            } cout<<"\nJobs Used: ";
            for(i=0;i<highest;i++){
                cout<<"\tJ"<<gantt[i];
            }
   cout<<"\nTotal Profit of Jobs: "<<total_profit<<" Units";

    cout<<"\n\n\n\n";
}
