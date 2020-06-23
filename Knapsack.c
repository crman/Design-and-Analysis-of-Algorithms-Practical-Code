#include<stdio.h>

void main()
{
    int n,last=0;
    float max,tp=0,tw=0,rw=0;
    printf("Enter Capacity : ");
    scanf("%f",&max);
    printf("Enter Number of objects : ");
    scanf("%d",&n);
    float w[n],p[n];
    float pw[n];
    time_t t1,t2;

    for(int i=0;i<n;i++)
    {
        printf("Enter Weight of Object %d : ",i+1);
        scanf("%f",&w[i]);
        printf("Enter Profit of Object %d : ",i+1);
        scanf("%f",&p[i]);
    }

    time(&t1);
    for(int i=0;i<n;i++)
    {
        pw[i]=p[i]/w[i];  //profit/weight ratio...
    }


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(pw[j]<pw[j+1])
            {
                float temp=w[j];
                w[j]=w[j+1];
                w[j+1]=temp;

                float temp1=p[j];           //   Sorting in descending order according to p/w ratio
                p[j]=p[j+1];
                p[j+1]=temp1;

                float temp2=pw[j];
                pw[j]=pw[j+1];
                pw[j+1]=temp2;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(w[i]<=max)
        {
            max= max-w[i];
            tp=tp+p[i];
            last=i;
        }                               //Calculation of maximum profit...
    }


    tp=tp+(max/w[last+1])*p[last+1];
    time(&t2);
          //  max=max-w[k];

    t2=t2-t1;
    printf("Maximum Profit : %f",tp);
    printf("\nTime : %ld",t2*1000);
}
