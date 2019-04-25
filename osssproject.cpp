#include<stdio.h> 
 
int main() 
{ 
      int i, lim, total = 0, x, count = 0, time_quantum,j,wt; 
      
	  int wait_time = 0, turnaround_time = 0,pos,z,p[10],prio[10], a_time[10], b_time[10], tem[10],b; 
      
	  float average_wait_time, average_turnaround_time;
      
	  printf("\n    WELCOME DEAR in Process SCheduling with dynamically changing Priority \n\n\t------Please enter Total Number of Processes You want to execute:"); 
      
	  scanf("%d", &lim); 
      char c;
	  x = lim; 
      for(i = 0,c='A'; i < lim;c++, i++) 
      {
	    p[i]=i+1;
	   
	    prio[i]=0;
            printf("\nEnter total Details of Process[%c]\n", c);
            printf("Arrival Time:\t");
            scanf("%d", &a_time[i]);
            printf("Burst Time:\t");
            scanf("%d", &b_time[i]); 
            tem[i] = b_time[i];
      }
	   
      printf("\nEnter the Time Quantum:"); 
      scanf("%d", &time_quantum); 
      printf("\nProcess ID\t\tArival_time\t\tBurst Time\t Turnaround Time\t Waiting Time\t Priority\n");
      for(total = 0, i = 0; x != 0;) 
      { 

		    for(z=0;z<lim;z++)
		    {
			int temp1;
			pos=z;
			for(j=z+1;j<lim;j++)
			{
			    if(prio[j]<prio[pos])
				pos=j;
			}
		 
		temp1=prio[z];
	
		prio[z]=prio[pos];
	
		prio[pos]=temp1;
		 
			temp1=b_time[z];
			b_time[z]=b_time[pos];
			b_time[pos]=temp1;
		 			temp1=a_time[z];
				a_time[z]=a_time[pos];
			a_time[pos]=temp1;

			temp1=p[z];
				p[z]=p[pos];
			p[pos]=temp1;

			temp1=tem[z];
				tem[z]=tem[pos];
			tem[pos]=temp1;
		    }
		{
		}
            
			if(tem[i] <= time_quantum && tem[i] > 0) 
            { 
                  total = total + tem[i]; 
                  tem[i] = 0; 
                  count = 1; 
            } 
            
			else if(tem[i] > 0) 
            { 
                  tem[i] = tem[i] - time_quantum; 
                  total = total + time_quantum; 
            } 

	for(b=0,c='A';b<lim;c++,b++)
		{
			if(b==i)
			prio[b]+=1;
			else
			prio[b]+=2;
		}

            if(tem[i] == 0 && count == 1) 
            { 
                  x--; 
                  printf("\nProcess[%c]\t\t%d\t\t\t%d\t\t\t %d\t\t\t %d\t\t%d", p[i]+64,a_time[i], b_time[i], total - a_time[i], total - a_time[i] - b_time[i],prio[i]);
                  wait_time = wait_time + total - a_time[i] - b_time[i]; 
                  turnaround_time = turnaround_time + total - a_time[i]; 
                    wt=0;
                  wt=wt+wait_time;
                  
                  count = 0; 
                
            } 
            if(i == lim - 1) 
            {
                  i = 0; 
            
			}
            else if(a_time[i + 1] <= total) 
            {
                  i++;
            
			}
            else 
            {
                  i = 0;
            
			}		
      } 
      average_wait_time=wt/lim;
      printf("\n\nAverage waiting time is  %d",average_wait_time);
      return 0; 
}

